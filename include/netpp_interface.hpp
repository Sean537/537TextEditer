#ifndef NETPP_INTERFACE
#define NETPP_INTERFACE

#include <iostream>
#include <functional>

#include "netpp.h"

using namespace std;

GoString string_to_gostr(string s){
	return GoString{s.data(), s.size()};
}

namespace netpp{
	class socket;
	class listener;
	
	class socket{
		public:
			virtual void connect(string to){}
			
			virtual string read(){}
			virtual socket& operator>>(string& buf){}
			
			virtual void write(string data_){}
			virtual socket& operator<<(string data_){}
			
			virtual void non_blocking(){}
			
			virtual void set_dead_time(int ms){}
			
			virtual void close(){};
	};
	
	class listener{
		public:
			virtual void bind(
				string target, 
				function<void(socket&)> callback
			){}
			
			virtual socket* accept(){}
			
			virtual void close(){}
	};
}

#endif
