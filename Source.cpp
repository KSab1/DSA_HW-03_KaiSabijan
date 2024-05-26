#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <conio.h>

using namespace std;

struct Point {
    int row;
    int col;
};

void plotBoard(const vector<vector<char>>& board, Point current, Point start, Point end) {
    system("cls");
    for (const auto& row : board) {
        for (char c : row) {
            cout << c;
        }
        cout << endl;
    }
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << endl;
}

int main() {
    Point start, end, current, prev;
    int rows = 20, cols = 40;
    vector<vector<char>> board(rows, vector<char>(cols, '-'));

    cout << "Enter row (1-20) of point A: ";
    cin >> start.row;

    cout << "Enter column (1-40) of point A: ";
    cin >> start.col;
    board[start.row - 1][start.col - 1] = 'A';

    cout << "Enter row (1-20) of point B: ";
    cin >> end.row;

    cout << "Enter column (1-40) of point A: ";
    cin >> end.col;
    board[end.row - 1][end.col - 1] = 'B';

    current = start;
    prev = start;
    board[current.row - 1][current.col - 1] = 'x';

    while (current.row != end.row || current.col != end.col) {
        plotBoard(board, current, start, end);

        if (current.col < end.col) {
            current.col++;
        }
        else if (current.col > end.col) {
            current.col--;
        }
        else if (current.row < end.row) {
            current.row++;
        }
        else if (current.row > end.row) {
            current.row--;
        }

        board[start.row - 1][start.col - 1] = 'A';
        board[prev.row - 1][prev.col - 1] = '-';
        board[current.row - 1][current.col - 1] = 'x';
        prev = current;
    }

    plotBoard(board, current, start, end);
    cout << "Reached endpoint!" << endl;

    return 0;
}