AutomatedMakefile = am
CC = g++

FILES = RecursiveIntegration.o Problem22_1.o RombergIntegration.o
EXECUTABLE = 

PROJECT_PATH = $(CURRENT_DIR)
INC_DIRS = -I$(CURRENT_DIR)/CSC2110
LIB_DIRS = -L$(CURRENT_DIR)/CSC2110
LIBS = -lCSC2110

COMPILE = $(CC) $(INC_DIRS) -c
LINK = $(CC) $(LIB_DIRS)

all: Project

Project: 					$(FILES)
							$(LINK) $(EXECUTABLE) $(FILES) $(LIBS)


RecursiveIntegration.o:		RecursiveIntegration.h RecursiveIntegration.cpp
							$(COMPILE) RecursiveIntegration.cpp
				
RombergIntegration.o:		RombergIntegration.h RombergIntegration.cpp
							$(COMPILE) RombergIntegration.cpp

Problem22_1.o:				Problem22_1.h Problem22_1.cpp
							$(COMPILE) Problem22_1.cpp