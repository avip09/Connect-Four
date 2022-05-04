//
//  driver.cpp
//  ConnectFourNew
//
//  Created by Avi Patel on 5/4/22.
//

#include <iostream>
#include <vector>
using namespace std;

class MasterClass {
private:
    vector< vector<char> > board;
    vector< pair<int, int> > validPos;
    
public:
    void printBoard() {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 7; ++j) {
                cout << board[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
    void initBoard() {
        vector<char> push;
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 7; ++j) {
                push.push_back('.');
            }
            board.push_back(push);
        }
    }
    void game() {
        bool winner = false;
        char player = '1';
        for (int i = 0; i < 7; ++i) {
            validPos.push_back({5, i});
        }
        
        while (!winner) {
            printBoard();
            bool valid = false;
            int row = 0;
            int col = 0;
            while (!valid) {
                cout << "What is the row of your move, Player " << player << "? \n";
                cin >> row;
                cout << "What is the column of your move, Player " << player << "? \n";
                cin >> col;
                pair<int, int> check = {row, col};
                for (int i = 0; i < validPos.size(); ++i) {
                    if (check == validPos[i]) {
                        validPos.erase(validPos.begin() + i);
                        valid = true;
                        break;
                    }
                }
            }
            board[row][col] = player;
            if (row != 0) {
                validPos.push_back({row - 1, col});
            }
            // 4 in a row check
            for (int i = 0; i < 6; ++i) { // rows
                if ((board[i][0] == player && board[i][1] == player && board[i][2] == player && board[i][3] == player) || (board[i][1] == player && board[i][2] == player && board[i][3] == player && board[i][4] == player) || (board[i][2] == player && board[i][3] == player && board[i][4] == player && board[i][5] == player) || (board[i][3] == player && board[i][4] == player && board[i][5] == player && board[i][6] == player)) {
                    winner = true;
                    cout << "Player " << player << ", you win!\n";
                }
            }
            for (int i = 0; i < 7; ++i) { // cols
                if ((board[0][i] == player && board[1][i] == player && board[2][i] == player && board[3][i] == player) || (board[1][i] == player && board[2][i] == player && board[3][i] == player && board[4][i] == player) || (board[2][i] == player && board[3][i] == player && board[4][i] == player && board[5][i] == player) || (board[3][i] == player && board[4][i] == player && board[5][i] == player && board[6][i] == player)) {
                    winner = true;
                    cout << "Player " << player << ", you win!\n";
                }
            }
            if ((board[3][0] == player && board[2][1] == player && board[1][2] == player && board[0][3] == player) || (board[4][0] == player && board[3][1] == player && board[2][2] == player && board[1][3] == player) || (board[3][1] == player && board[2][2] == player && board[1][3] == player && board[0][4] == player) || (board[5][0] == player && board[4][1] == player && board[3][2] == player && board[2][3] == player) || (board[4][1] == player && board[3][2] == player && board[2][3] == player && board[1][4] == player) || (board[3][2] == player && board[2][3] == player && board[1][4] == player && board[0][5] == player) || (board[5][1] == player && board[4][2] == player && board[3][3] == player && board[2][4] == player) || (board[4][2] == player && board[3][3] == player && board[2][4] == player && board[1][5] == player) || (board[3][3] == player && board[2][4] == player && board[1][5] == player && board[0][6] == player) || (board[5][2] == player && board[4][3] == player && board[3][4] == player && board[2][5] == player) || (board[4][3] == player && board[3][4] == player && board[2][5] == player && board[1][6] == player) || (board[5][3] == player && board[4][4] == player && board[3][5] == player && board[2][6] == player)) {
                winner = true;
                cout << "Player " << player << ", you win!\n";
            }
            if ((board[2][0] == player && board[3][1] == player && board[4][2] == player && board[5][3] == player) || (board[1][0] == player && board[2][1] == player && board[3][2] == player && board[4][3] == player) || (board[2][1] == player && board[3][2] == player && board[4][3] == player && board[5][4] == player) || (board[0][0] == player && board[1][1] == player && board[2][2] == player && board[3][3] == player) || (board[1][1] == player && board[2][2] == player && board[3][3] == player && board[4][4] == player) || (board[2][2] == player && board[3][3] == player && board[4][4] == player && board[5][5] == player) || (board[0][1] == player && board[1][2] == player && board[2][3] == player && board[3][4] == player) || (board[1][2] == player && board[2][3] == player && board[3][4] == player && board[4][5] == player) || (board[2][3] == player && board[3][4] == player && board[4][5] == player && board[5][6] == player) || (board[0][2] == player && board[1][3] == player && board[2][4] == player && board[3][5] == player) || (board[1][3] == player && board[2][4] == player && board[3][5] == player && board[4][6] == player) || (board[0][3] == player && board[1][4] == player && board[2][5] == player && board[3][6] == player)) {
                winner = true;
                cout << "Player " << player << ", you win!\n";
            }
                                         
            
            // switch player
            if (player == '1') {
                player = '2';
            }
            else {
                player = '1';
            }
        }
        printBoard();
    }
    
};

int main(int argc, char * argv[]) {
    cout << "Welcome to Connect Four, Players 1 and 2! Player 1, you will start.\n";
    MasterClass playOn;
    playOn.initBoard();
    playOn.game();
    return 0;
}
