/*
Time Taken:
------------
Reading: 0.6m
Getting Rules: 5.5m
Thinking: 8m
Writing Algorithm: 75m 
Coding: 60m (not certain)
Debugging: 45m
Total: 194m
*/
=====================================================================
Iformations:
-------------
Start:
    - Player 1 has odd numbers : 1, 3, 5, 7, 9
    - Player 2 has even numbers: 0, 2, 4, 6, 8
Display:
    - 3 * 3 board
Game Rules:
    - Player 1 plays first
    - Each number used only once
Winning:
    - The first person to complete a line that adds up to 15
======================================================================
odd =  [1, 3, 5, 7, 9]
even = [0, 2, 4, 6, 8]
board = [
    [15, 15, 15],
    [15, 15, 15],
    [15, 15, 15]
]
end_game = False
game_round = 1

start_message():
    print "Player 1 has these odd numbers: 1, 3, 5, 7, 9"
    print "Player 2 has these even numbers: 0, 2, 4, 6, 8"
    print "First player to complete a line that adds up to 15 is the winner"
    print "Good luck!"


display_state():
    print """
        ====================

         * | * | * 
        -----------
         * | * | * 
        -----------
         * | * | * 

        ____________________

    """
    // Change * to the numbers taken


take_input(nums):
    input n
    while n not in nums:
        input n
    return n


take_ordinate(name):
    input ord
    while ord not in [1, 2, 3]:
        print "Oops not available " + name + "!"
        input ord
    return ord


take_position():
    row = take_ordinate("row")
    col = take_ordinate("column")
    return [row - 1, col - 1]


update_state(n, nums, position):
    add n at position in board
    clear n from nums
    display_state()


check_result(state):
    if any horizontal line values sum equal to 15:
        return true
    else if any vertical line sum equal to 15:
        return true
    else if any diagonal line sum equal to 15:
        return true
    else
        return false


player_turn(nums):
    global end_game
    player = take_input(nums)

    pos = take_position()
    while position of board not empty:
        pos = take_position()
    
    update_state(player, nums, pos)
    end_game = check_result(board)


end_message():
    if end_game == true:
        if game_round % 2 == 1:
            print "Player 2 wins!"
        else:
            print "Player 1 wins!"
    else:
        print "Draw!"


main():
    global game_round
    start_message()
    display_state()
    while not end_game and game_round <= 9:
        if game_round % 2 == 1:
            print "Player 1 plays"
            print "Available numbers are: " + odd
            player_turn(odd)
        else:
            print "Player 2 plays"
            print "Available numbers are: " + even
            player_turn(even)
        increment game_round by 1
    end_message()

main()
