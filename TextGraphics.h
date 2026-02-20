#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// Conditional compilation for Linux-specific non-blocking input
#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else //Mac / Linux
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#endif

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

const int WIDTH = 143;
const int HEIGHT = 16;
const int ESCAPE = 27;

enum class Color {
    Default,
    Black,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    White
};

class TextGraphics
{
    public:
        TextGraphics();
        int width() { return WIDTH; }
        int height() { return HEIGHT; }
        void draw();
        void clearScreen();
        int readKey();
        void putCharAt(int i, int j, char ch, Color color = Color::Default);
        void putStringAt(int i, int j, const std::string& text, Color color = Color::Default);
        char getCharAt(int i, int j) { return pixels[i][j]; }
        Color getColorAt(int i, int j) { return colors[i][j]; }
        void sleepMs(int ms);
    private:
        void hideCursor();
        void showCursor();
        std::string getAnsiColor(Color color);
        void setConsoleSize(int cols, int rows);

        char pixels[HEIGHT][WIDTH];
        Color colors[HEIGHT][WIDTH];
};
