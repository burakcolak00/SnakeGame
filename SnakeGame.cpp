#include <iostream>
#include <conio.h>      // For _kbhit() and _getch()
#include <windows.h>    // For Sleep() and console functions
#include <vector>
using namespace std;

const int width = 40;
const int height = 20;
int x, y, fruitX, fruitY, score;
int dx, dy;  // direction
bool gameOver;
vector<pair<int, int>> snake;

// Move the cursor to a specific location in the terminal
void gotoXY(int x, int y);

// Initialize the game state
void setup();

// Handle keyboard input using WASD
void input();

// Update game logic (movement, collision, fruit)
void logic();

// Draw the game state in the terminal
void draw();

// Main game loop
int main() {
    bool menu = true;
    // Display menu
    while(menu){
        cout << "Welcome to Snake Game Prepared by Burak COLAK!\n";
        cout << "Press 's' to start or 'x' to exit.\n";
        char choice = _getch();
        if (choice == 's') {
            cout << "Starting game...\n";
            Sleep(1000); // Pause for 1 second
            system("cls"); // Clear the console
            menu = false; // Exit menu loop
            break;
        } else if (choice == 'x') {
            cout << "Exiting game...\n";
            Sleep(1000); // Pause for 1 second
            return 0;
        }
    }
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(100); // Controls speed
    }
    gotoXY(0, height + 3);
    cout << "Game Over!\n";
    cout << "Final Score: " << score << "\n";
    cout << "Exit in 2 seconds...\n";
    Sleep(2000); // Pause for 2 seconds
    return 0;
}

void gotoXY(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setup() {
    gameOver = false;
    x = width / 2;
    y = height / 2;
    snake.clear();
    snake.push_back({x, y});
    dx = 1; dy = 0;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'w': if(dy!=1){dx = 0; dy = -1;} break;
            case 's': if(dy!=-1){dx = 0; dy = 1;} break;
            case 'a': if(dx!=1){dx = -1; dy = 0;} break;
            case 'd': if(dx!=-1){dx = 1; dy = 0;} break;
            case 'x': gameOver = true; break;
        }
    }
}

void logic() {
    x += dx;
    y += dy;

    // Wall collision
    if (x < 0 || x >= width || y < 0 || y >= height)
        gameOver = true;

    // Self-collision
    for (auto &part : snake)
        if (part.first == x && part.second == y)
            gameOver = true;

    // Move snake
    snake.insert(snake.begin(), {x, y});
    if (x == fruitX && y == fruitY) {
        score++;
        fruitX = rand() % width;
        fruitY = rand() % height;
    } else {
        snake.pop_back();  // remove tail
    }
}

void draw() {
    gotoXY(0, 0);
    for (int i = 0; i < width+2; i++) cout << "#";
    cout << "\n";

    for (int i = 0; i < height; i++) {
        cout << "#";
        for (int j = 0; j < width; j++) {
            if (i == y && j == x)
                cout << "O"; // Snake head
            else if (i == fruitY && j == fruitX)
                cout << "*"; // Fruit
            else {
                bool print = false;
                for (auto &part : snake) {
                    if (part.first == j && part.second == i) {
                        cout << "o"; // Snake body
                        print = true;
                        break;
                    }
                }
                if (!print) cout << " ";
            }
        }
        cout << "#\n";
    }

    for (int i = 0; i < width+2; i++) cout << "#";
    cout << "\nScore: " << score << "\n";
}


