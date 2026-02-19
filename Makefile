CC ?= gcc
BUILD_DIR := build
TARGET := $(BUILD_DIR)/app.exe
SRC_DIR := src
SOURCES := $(wildcard $(SRC_DIR)/*.c)

# FreeGLUT bundled in this repository
INCLUDES := -Iinclude
LIB_DIR := lib/x64
LIBS := -L$(LIB_DIR) -lfreeglut -lopengl32 -lglu32 -lgdi32 -lwinmm
DLL_SOURCE := bin/x64/freeglut.dll
DLL_TARGET := $(BUILD_DIR)/freeglut.dll
DLL_SOURCE_WIN := bin\\x64\\freeglut.dll
DLL_TARGET_WIN := $(BUILD_DIR)\\freeglut.dll

CFLAGS ?= -Wall -Wextra -g

all: $(TARGET) $(DLL_TARGET)

$(BUILD_DIR):
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)

$(TARGET): $(BUILD_DIR) $(SOURCES)
	$(CC) $(CFLAGS) $(INCLUDES) $(SOURCES) -o $@ $(LIBS)

$(DLL_TARGET): $(BUILD_DIR) $(DLL_SOURCE)
	cmd /C copy /Y "$(DLL_SOURCE_WIN)" "$(DLL_TARGET_WIN)" >NUL

run: all
	.\\$(TARGET)

clean:
	if exist $(BUILD_DIR) rmdir /Q /S $(BUILD_DIR)

.PHONY: all run clean
