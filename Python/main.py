"""
# Project: Tic-Tac-Toe with numbers
# Author: Ahmed Shaaban
# Date: Feb. 24 2022
# Version: 1.0
"""

odd = [1, 3, 5, 7, 9]
even = [0, 2, 4, 6, 8]

# Initial value type is int and equal to 15 which will prevent errors in check_result() function
board = [
    [15, 15, 15],
    [15, 15, 15],
    [15, 15, 15]
]
win_game = False
game_turn = 1


def start_message():
    print("Welcome in Tic-Tac-Toe with numbers!")
    print("Player 1 has these odd numbers: 1, 3, 5, 7, 9")
    print("Player 2 has these even numbers: 0, 2, 4, 6, 8")
    print("There is 3 rows (1:3) ordered from top to bottom.")
    print("There is 3 columns (1:3) ordered from left to righ.")
    print("First player to complete a line that adds up to 15 is the winner.")
    print("Good luck!")


# Displaying the full board
def display_state():
    print('=' * 30, '\n')
    for i in range(0, 3):
        for j in range(0, 3):
            if j == 2:
                print('', board[i][j] if board[i][j] != 15 else '*')
            else:
                print('', board[i][j] if board[i][j] != 15 else '*', '|', end='')
        if i != 2:
            print('-' * 11)
    print('_' * 30, '\n')


def take_number(nums):
    n = int(input("Enter a number: "))
    while n not in nums: # Check if the taken number is valid
        print("Oops not available number!")
        n = int(input("Enter a number: "))
    return n


def take_ordinate(name):
    ord = int(input("Enter a " + name + " number: "))
    while ord not in [1, 2, 3]: # Check if the taken ordinate number is valid
        print("Oops not available " + name + "!")
        ord = int(input("Enter a " + name + " number: "))
    return ord


def take_position():
    row = take_ordinate("row") # Take row number
    col = take_ordinate("column") # Take column number
    return [row - 1, col - 1]


# Set the number on board and remove it from available numbers
def update_state(n, nums, pos):
    board[pos[0]][pos[1]] = n
    nums.remove(n)
    display_state()


# check all cases of wins
def check_result():
    # Checks horizontal rows
    if board[0][0] + board[0][1] + board[0][2] == 15 \
            or board[1][0] + board[1][1] + board[1][2] == 15 \
            or board[2][0] + board[2][1] + board[2][2] == 15:
        return True
    # Checks vertical columns
    elif board[0][0] + board[1][0] + board[2][0] == 15 \
            or board[0][1] + board[1][1] + board[2][1] == 15 \
            or board[0][2] + board[1][2] + board[2][2] == 15:
        return True
    # checks diagonal lines
    elif board[0][0] + board[1][1] + board[2][2] == 15 \
            or board[0][2] + board[1][1] + board[2][0] == 15:
        return True
    else:
        return False


# Full turn for player
def player_turn(nums):
    global win_game
    player = take_number(nums)
    print('-' * 20)

    pos = take_position()
    while board[pos[0]][pos[1]] != 15: # While the position is taken before
        print("Oops not available position!")
        pos = take_position()

    update_state(player, nums, pos)
    win_game = check_result()


def end_message():
    if win_game: # If any player won
        if game_turn % 2 == 1: # If the game ended and the next round is for player 1, player 2 wins
            print("Player 2 wins!")
        else:
            print("Player 1 wins!")
    else:
        print("Draw!")


def main():
    start_message()
    display_state()
    global game_turn
    while not win_game and game_turn <= 9:
        if game_turn % 2 == 1:
            print("Player 1 plays")
            print("Available numbers are:", odd)
            player_turn(odd)
        else:
            print("Player 2 plays")
            print("Available numbers are:", even)
            player_turn(even)
        game_turn += 1
    end_message()


main()
