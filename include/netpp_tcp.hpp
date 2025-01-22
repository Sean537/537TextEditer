#ifndef NETPP_TCP_HPP
#define NETPP_TCP_HPP

#include <iostream>
#include <vector>

#include "netpp_interface.hpp"

using namespace std;

const int n_init = -1;

namespace netpp{
	//锟斤拷锟斤拷
	class tcp_socket;
	class tcp_listener;
	
	//锟斤拷锟斤拷socket锟阶斤拷锟斤拷
	class tcp_socket : public socket{
		public:
			friend class tcp_listener;
			
			tcp_socket(){}
			
			tcp_socket(string ip){
				connect(ip);
			}
				
			virtual void connect(string ip){
				id = Connect(string_to_gostr("tcp"), 
							string_to_gostr(ip));
				if(id < 0){
					GoString buf{nullptr, 1024};
					GetError(id, &buf);
					id = n_init;
					throw string(buf.p);
				}
			}
			
			virtual string read(){
				if(id == n_init)
					throw string("Not initialized!");
				
				if(time_out != n_init)
					NonBlocking(id, time_out);
				
				GoString data_{nullptr, 1024};
				
				auto err = Read(&data_, id);
				
				if(err < 0){
					GoString buf{nullptr, 1024};
					GetError(err, &buf);
					throw string(buf.p);
				}
				
				return string(data_.p);
			}
			
			virtual socket& operator>>(string &buf){
				buf = read();
				return *this;
			}
			
			virtual void write(string buf){
				if(id == n_init)
					throw string("Not initialized!");
				
				if(time_out != n_init)
					NonBlocking(id, time_out);
				
				auto err = Write(string_to_gostr(buf), id);
				if(err < 0){
					GoString buf{nullptr, 1024};
					GetError(err, &buf);
					throw string(buf.p);
				}
			}
			
			virtual socket& operator<<(string data_){
				write(data_);
				return *this;
			}
			
			virtual void set_dead_time(int ms){
				time_out = ms;
			}
			
			virtual void non_blocking(){
				time_out = 0;
			}
			
			virtual void close(){
				if(id == n_init)
					throw string("Not initialized!");
								
				auto err = CloseSock(id);
				if(err < 0){
					GoString buf{nullptr, 1024};
					GetError(err, &buf);
					throw string(buf.p);
				}
			}
		private:
			int id = n_init;
			int time_out = n_init;
	};
	
	//锟斤拷锟斤拷锟斤拷锟斤拷锟�
	class tcp_listener : public listener{
		public:
			tcp_listener(){}
			
			tcp_listener(string ip){
				listen(ip);
			}
			
			virtual void listen(string ip){
				id = Listen(string_to_gostr("tcp"), 
							string_to_gostr(ip));
				if(id < 0){
					GoString buf{nullptr, 1024};
					GetError(id, &buf);
					id = n_init;
					throw string(buf.p);
				}
			}
			
			virtual socket* accept(){
				if(id == n_init){
					throw string("Not initialized!");
				}
				
				int sock_id = Accept(id);
				
				if(sock_id < 0){
					char data_[1024];
					GoString buf{data_, 1024};
					GetError(sock_id, &buf);
					throw string(buf.p);
				}
				
				tcp_socket* tmp = new tcp_socket;
				tmp->id = sock_id;
				
				return tmp;
			}
			
			virtual void close(){
				if(id == n_init)
					throw string("Not initialized!");
					
				auto err = CloseSock(id);
				if(err < 0){
					GoString buf{nullptr, 1024};
					GetError(err, &buf);
					throw string(buf.p);
				}
			}
		private:
			int id = n_init;
	};
	
	struct tcp{ string ip; };
	
	listener* listen(tcp msg){
		listener* new_ls = new tcp_listener(msg.ip);
		
		return new_ls;
	}
	
	socket* conn(tcp msg){
		socket* new_conn = new tcp_socket(msg.ip);
		
		return new_conn;		
	}
}

#endif//netpp.hpp
