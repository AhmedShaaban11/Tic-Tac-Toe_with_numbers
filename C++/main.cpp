#include <iostream>
#include <vector>
using namespace std;

vector <int> odd = {1, 3, 5, 7, 9}, even = {0, 2, 4, 6, 8};
int board[3][3] = {
        {15, 15 ,15},
        {15, 15, 15},
        {15, 15, 15}
};
bool win_game = false;
int game_turn = 1; 

void print_vector(vector <int> vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}

void start_message()
{
    cout << "Welcome in Tic-Tac-Toe with numbers!" << endl;
    cout << "Player 1 has these odd numbers: 1, 3, 5, 7, 9" << endl;
    cout << "Player 2 has these even numbers: 0, 2, 4, 6, 8" << endl;
    cout << "There is 3 rows (1:3) ordered from top to bottom." << endl;
    cout << "There is 3 columns (1:3) ordered from left to right." << endl;
    cout << "First player to complete a line that adds up to 15 is the winner." << endl;
    cout << "Good luck!" << endl;
}

void display_state()
{
    cout << "==============================" << '\n' << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
                cout << ' ' << ((board[i][j] == 15) ? '*' : char(board[i][j] + 48)); // '0' => 48 ASCII
            else
                cout << ' ' << ((board[i][j] == 15) ? '*' : char(board[i][j] + 48)) << ' ' << '|';
        }
        cout << endl;
        if (i != 2)
            cout << "-----------" << endl;
    }
    cout << "______________________________" << '\n' << endl;
}

int take_number(vector <int> nums)
{
    int n;
    bool found = false;
    do {
        cout << "Enter a number:"; cin >> n;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == n)
            {
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Oops not available number!" << endl;
    } while (!found);
    return n;
}

int take_ordinate(string name)
{
    int ord;
    cout << "Enter a " << name << " number:"; cin >> ord;
    while (ord != 1 && ord != 2 && ord != 3)
    {
        cout << "Oops not available " << name << "!" << endl;
        cout << "Enter a "<< name << " number:"; cin >> ord;
    }
}

vector <int> take_position()
{
    int row = take_ordinate("row");
    int col = take_ordinate("column");
    return {row - 1, col - 1};
}

void update_state(int n, vector <int>& nums, vector <int> pos)
{
    board[pos[0]][pos[1]] = n;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == n)
        {
            nums.erase(nums.begin() + i, nums.begin() + i + 1);
            nums.shrink_to_fit();
        }
    }
    display_state();
}

bool check_result()
{
    if (board[0][0] + board[0][1] + board[0][2] == 15
            or board[1][0] + board[1][1] + board[1][2] == 15
            or board[2][0] + board[2][1] + board[2][2] == 15)
        return true;
    else if (board[0][0] + board[1][0] + board[2][0] == 15
            or board[0][1] + board[1][1] + board[2][1] == 15
            or board[0][2] + board[1][2] + board[2][2] == 15)
        return true;
    else if (board[0][0] + board[1][1] + board[2][2] == 15
            or board[0][2] + board[1][1] + board[2][0] == 15)
        return true;
    else
        return false;
}

void player_turn(vector <int>& nums)
{
    int player = take_number(nums);
    cout << "--------------------" << endl;
    vector <int> pos;
    pos = take_position();
    while (board[pos[0]][pos[1]] != 15)
    {
        cout << "Oops unavailable position!" << endl;
        pos = take_position();
    }
    update_state(player, nums, pos);
    win_game = check_result();
}

void end_message()
{
    if (win_game)
    {
        if (game_turn % 2 == 1)
            cout << "Player 2 wins!" << endl;
        else
            cout << "Player 1 wins!" << endl;
    } else
        cout << "Draw!" << endl;
}

int main() {
    start_message();
    display_state();
    while (not win_game && game_turn <= 9)
    {
        if (game_turn % 2 == 1)
        {
            cout << "Player 1 plays" << endl;
            cout << "Available numbers are: ";
            print_vector(odd);
            player_turn(odd);
        }
        else
        {
            cout << "Player 2 plays" << endl;
            cout << "Available numbers are: ";
            print_vector(even);
            player_turn(even);
        }
        game_turn++;
    }
    end_message();
    return 0;
}
