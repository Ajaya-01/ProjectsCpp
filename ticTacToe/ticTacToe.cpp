#include <iostream>
using namespace std;

char board[3][3]; //3x3 game board
char currentPlayer;

void initializeBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
        
    }
    
}

void printBoard()
{
    cout << " 0 1 2" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "  ------" << endl;
        
    }
    
}

bool checkWin()
{
    /* Check rows and columns */
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) || 
        (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))
        {
            return true;
        }
        
    }
    /* Check diagonals*/
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer ||
    (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))
    {
        return true;
    }
    return false;
}

bool isBoardFull() 
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
        
    }
    return true;
}

void switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O': 'X';
}

int main()
{
    initializeBoard();
    currentPlayer = 'X';
    int row, col;


    while (true)
    {
        printBoard();
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        /* This is loop -holes : If char/string entered it will goes infinite loop. */

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ')
        {
            cout << "Invalid move. Try again." << endl;
            continue;
        }
        
        board[row][col] = currentPlayer;
        
        if (checkWin())
        {
            printBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        if (isBoardFull())
        {
            printBoard();
            cout << "It's a draw!" << endl;
            break;
        }
        
        switchPlayer();
    }
    
    return 0;
}