# 537文本编辑器（537 Text Editer）
<h3>这是537工作室开源的“537文本编辑器”1.3版本（32位）源代码。</h3>
<h4>537工作室官方网站：<a href="https://www.537studio.com" target="_blank">https://www.537studio.com</a>。大家可以在我们的官方网站上获取537文本编辑器的最新版本。</h4>
<h2>软件介绍：</h2>
<h4>537文本编辑器是537工作室自2023年5月11日成立以来开发的第一款GUI应用程序，发布于2023年6月1日537工作室“Think Different非同凡‘想’”发布会。它虽然在许多方面不如其它文本编辑器，却开拓了我们的GUI软件开发进程。</h4>
<h4>软件使用C++和纯Win32开发。这个软件更像是个“玩具项目”，我们在其中内置了许多测试功能，但仍不是很完善。于是将其1.3旧版本开源，希望大家能在GitHub上共同改进这个项目！</h4>
<h2>开发环境：</h2>
  <h4>代码编辑器：Dev-C++5.11</h4>
  <h4>编译器：TDM-GCC4.9.2</h4>
  <h4>C++版本：ISO C++11</h4>
  <h4>操作系统：Windows</h4>
  <h4>第三方库（指非ISO C++标准下的库文件）：windows.h（纯Win32编写）</h4>
<h2>文件目录：</h2>
  <li>537文本编辑器.dev————项目文件，可直接使用Dev-C++打开。打开项目仅需打开此文件，无需手动打开代码文件。</li>
  <li>537文本编辑器.ico————图标文件，已包含在“537文本编辑器.dev”中。</li>
  <li>537text.cpp————C++代码文件，写了软件的主要代码。已包含在“537文本编辑器.dev”中，无需手动打开。直接运行会报错，因为没有项目文件的信息。</li>
  <li>537text.h————C语言头文件，软件主要头文件，写了一些宏定义。已包含在“537文本编辑器.dev”中，无需手动打开。</li>
  <li>resource.rc————资源文件，主要写了软件的菜单栏，其它内容都包含在了项目文件中。已包含在“537文本编辑器.dev”中，无需手动打开。</li>
  <li>LICENCE————协议文件，内容是GN宽通用公共许可协议。请在协议许可的内容范围进行操作。</li>
  <li>其它————编辑器自动生成的一些文件，有些存储了“537文本编辑器.dev”中的某些数据，有些是编译器生成的，如Makefile.wim、537text.o等等。请勿删除编辑器生成的文件，编译器的文件在您编译时都会重新生成。</li>
<h2>To Do清单：</h2>
<li>支持UTF-8等宽字节编码</li>
<li>加入如检查更新等网络功能</li>
<li>将文本编辑框（EDIT）改成富文本编辑框（RichEdit）</li>
<h3>更多随大家各自想法。希望大家共同学习进步！</h3>
