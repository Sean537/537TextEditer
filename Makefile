# Project: 537 Text Editor
# Makefile created by Dev-C++ 5.11

OUTPUT=X86

CPP      = g++ -std=c++11
CC       = gcc
WINDRES  = windres
RES      = 537TextEditor_AppInfo.res
OBJ      = 537main.o $(RES)
LINKOBJ  = 537main.o $(RES)
INCS     = -I"./include"
CXXINCS  = -I"./include"

ifeq ($(OUTPUT), X64)
LIBS     = -L"./lib" -static-libgcc -lnetpp -mwindows -m64
BIN      = 537TextEditor_x64.exe
CXXFLAGS = $(CXXINCS) -m64
CFLAGS   = $(INCS) -m64
else
LIBS     = -L"./lib" -static-libgcc -lnetpp -mwindows -m32
BIN      = 537TextEditor_x86.exe
CXXFLAGS = $(CXXINCS) -m32
CFLAGS   = $(INCS) -m32
endif

# Using rm directives on Windows often fails
RM       = del

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

537main.o: 537main.cpp
	$(CPP) -c 537main.cpp -o 537main.o $(CXXFLAGS)

537TextEditor_AppInfo.res: 537TextEditor_AppInfo.rc resource.rc
	$(WINDRES) -i 537TextEditor_AppInfo.rc -F pe-i386 --input-format=rc -o 537TextEditor_AppInfo.res -O coff

