# Snake Game

A classic Snake game playable in the Windows terminal, written in C++. Built using simple console manipulation (no external libraries).

## 🎮 Features

- Real-time snake movement using `W`, `A`, `S`, `D`
- Fruit spawning and score tracking
- Self and wall collision detection
- ASCII graphics rendered directly in terminal
- Lightweight and fast (runs on any Windows terminal)

## 📸 Preview
Below is a sample game screen:

##########################################
#                           *            #
#                                        #
#     ooooO                              #
#                                        #
#                                        #
##########################################
Score: 4


## 🛠️ How It Works

The game uses:

- `SetConsoleCursorPosition()` for cursor movement
- `_kbhit()` and `_getch()` for non-blocking input
- `Sleep()` to control game speed
- Vectors to represent the snake’s body
- Simple game loop structure

## 🚀 Getting Started

### Requirements

- Windows OS
- A C++ compiler like `g++` or Visual Studio

Prepared by:
Burak Colak