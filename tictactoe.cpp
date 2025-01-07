#include <iostream>
#include <ctime>
#include <algorithm> 
using namespace std;

void board(char *s)
{
    cout << "     |     |     " << endl;
    cout << "  " << s[0] << "  |  " << s[1] << "  |  " << s[2] << "   " << endl;
    cout << "_____|_____|_____" << endl;

    cout << "     |     |     " << endl;
    cout << "  " << s[3] << "  |  " << s[4] << "  |  " << s[5] << "   " << endl;
    cout << "_____|_____|_____" << endl;

    cout << "     |     |     " << endl;
    cout << "  " << s[6] << "  |  " << s[7] << "  |  " << s[8] << "   " << endl;
}

void playermove(char *s, char player)
{
    int n;
    do
    {
        cout << "Enter any number from 1-9:" << endl;
        cin >> n;
        if (n >= 1 && n <= 9 && s[n - 1] == ' ')
        {
            s[n - 1] = player;
            break;
        }
        else
        {
            cout << "Invalid move! Please choose an empty spot within 1-9." << endl;
        }
    } while (true);
}

void compmove(char *s, char comp)
{
    int n;
    srand(time(NULL)); 

    while (true)
    {
        n = rand() % 9;
        if (s[n] == ' ')
        {
            s[n] = comp;
            break;
        }
    }
}

bool checkwin(char *s, char player, char comp)
{
    
    if (s[0] != ' ' && s[0] == s[1] && s[1] == s[2])
    {
        s[0] == player ? cout << "YOU WON!\n" : cout << "YOU LOSE\n";
    }
    else if (s[3] != ' ' && s[3] == s[4] && s[4] == s[5])
    {
        s[3] == player ? cout << "YOU WON!\n" : cout << "YOU LOSE\n";
    }
    else if (s[6] != ' ' && s[6] == s[7] && s[7] == s[8]) // Fixed condition (s[6] == s[7])
    {
        s[6] == player ? cout << "YOU WON!\n" : cout << "YOU LOSE\n";
    }
    else if (s[0] != ' ' && s[0] == s[3] && s[3] == s[6])
    {
        s[0] == player ? cout << "YOU WON\n" : cout << "YOU LOSE\n";
    }
    else if (s[1] != ' ' && s[1] == s[4] && s[4] == s[7])
    {
        s[1] == player ? cout << "YOU WON\n" : cout << "YOU LOSE\n";
    }
    else if (s[2] != ' ' && s[2] == s[5] && s[5] == s[8])
    {
        s[2] == player ? cout << "YOU WON\n" : cout << "YOU LOSE\n";
    }
    else if (s[0] != ' ' && s[0] == s[4] && s[4] == s[8])
    {
        s[0] == player ? cout << "YOU WON\n" : cout << "YOU LOSE\n";
    }
    else if (s[2] != ' ' && s[2] == s[4] && s[4] == s[6])
    {
        s[2] == player ? cout << "YOU WON\n" : cout << "YOU LOSE\n";
    }
    else
    {
        return false;
    }
    return true;
}

bool checktie(char *s)
{
    for (int i = 0; i < 9; i++)
    {
        if (s[i] == ' ')
        {
            return false;
        }
    }
    cout << "It's a TIE" << endl;
    return true;
}

int main()
{
    char s[9];
    fill(s, s + 9, ' '); 
    char player = 'X';
    char comp = 'O';
    bool run = true;

    board(s);
    while (run)
    {
        playermove(s, player);
        board(s);
        cout << endl;
        if (checkwin(s, player, comp))
        {
            run = false;
            break;
        }
        else if (checktie(s))
        {
            run = false;
            break;
        }
        compmove(s, comp);
        board(s);
        if (checkwin(s, player, comp))
        {
            run = false;
            break;
        }
        else if (checktie(s))
        {
            run = false;
            break;
        }
    }

    return 0;
}
