#!/bin/bash

animate_ascii() {
    clear
        local ascii_art = (
            "      ____              _     _    ____                       "
            "     / ___|  __ _ _   _(_) __| |  / ___| __ _ _ __ ___   ___  "
            "     \\___ \\ / _\` | | | | |/ _\`| | |  _ / _\` | '_ \\ _ \\ / _ \\ "
            "      ___) | (_| | |_| | | (_| | | |_| | (_| | | | | | |  __/ "
            "     |____/ \\__, |\\__,_|_|\\__,_|  \\____|\\__,_|_| |_| |_|\\___| "
            "               |_|                                            "
            )

        for line in "${ascii_art[@]}"; do
            echo "$line"
            sleep 0.3
            done
}

gameover() {
    local ascii_art = (
        "   ___                                  "
        "  / __|__ _ _ __  ___   _____ _____ _ _ "
        " | (_ / _\` | '  \\/ -_) / _ \\ V / -_) '_|"
        "  \\___\\__,_|_|_|_\\___| \\___/\\_/\\___|_|  "
        "                                         "
        )
        for line in "${ascii_art[@]}"; do
            echo "$line"
            sleep 0.2
            done
}

display_shape() {
    case "$1" in
        "circle")
        echo "   *****   "
        echo "  *     *  "
        echo " *       * "
        echo "  *     *  "
        echo "   *****   "
        ;;
        "star")
        echo "    *     "
        echo "   ***    "
        echo "  *****   "
        echo "   ***    "
        echo "    *     "
        ;;
        "umbrella")
        echo "  *****   "
        echo " *******  "
        echo "   ***    "
        echo "    |     "
        echo "    |     "
        ;;
        "triangle")
        echo "    *     "
        echo "   ***    "
        echo "  *****   "
        ;;
        esac
}

save_score() {
    echo "$1's Final Score: $2" >> scores.txt
        echo "$1's score saved successfully!"
}

validate_input() {
    for shape in "${shapes[@]}"; do
        if["$1" == "$shape"]; then
            return 0
            fi
            done
            return 1
}

dalgona_challenge() {
    while true; do
        shapes = ("circle" "star" "umbrella" "triangle")
        max_score = 250
        animate_ascii
        echo "                                                               "
        echo "       - - - - Welcome to Squid Game - Dalgona Challenge - - - -"
        echo "     ****************************************************************"
        echo "     *  Can you correctly identify the shape before time runs out?  *"
        echo "     *  You have only three attempts :)                             *"
        echo "     ****************************************************************"
        echo "_________________________________________________________________________"
        echo "_________________________________________________________________________"
        echo "Choose a mode:"
        echo "1. Play Alone"
        echo "2. Play with Computer"
        echo "3. 2 Player Mode"
        read mode

        echo "Select difficulty level: Easy (8 sec), Medium (6 sec), or Hard (4 sec)"
        read difficulty

        case "$difficulty" in
        "Easy" | "easy")
        time_limit = 8
        ;;
        "Medium" | "medium")
        time_limit = 6
        ;;
        "Hard" | "hard")
        time_limit = 4
        ;;
        *)
        echo "Invalid difficulty level selected. Defaulting to Easy."
        time_limit = 8
        ;;
        esac

            if["$mode" == "1"]; then
                score = 0
                attempts = 3
                while[$attempts - gt 0]; do
                    random_index = $((RANDOM % 4))
                    selected_shape = ${ shapes[$random_index] }
                    echo "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
                    echo "Generating a random shape..."
                    sleep 1
                    display_shape "$selected_shape"
                    echo "Enter the shape name (Circle, Star, Umbrella, Triangle) within $time_limit seconds:"
                    read - t $time_limit user_input

                    if[-z "$user_input"]; then
                        echo "Time's up! The correct shape was: $selected_shape"
                        attempts = $((attempts - 1))
                        elif validate_input "$user_input" && ["$user_input" == "$selected_shape"]; then
                        echo "Correct! You identified the shape!"
                        score = $((score + 10))
                    else
                        echo "Wrong guess! The correct shape was: $selected_shape"
                        attempts = $((attempts - 1))
                        fi

                        if[$attempts - eq 0]; then
                            echo "No attempts left. Game Over!"
                            break
                            fi

                            echo "Current Score: $score"
                            echo "Attempts Remaining: $attempts"
                            done

                            gameover
                            echo "Your final score: $score"
                            save_score "Player" $score

                            elif["$mode" == "2"]; then
                            player_score = 0
                            computer_score = 0
                            player_attempts = 3
                            computer_attempts = 3

                            while[$player_attempts - gt 0] || [$computer_attempts - gt 0]; do
                                if[$player_attempts - gt 0]; then
                                    random_index = $((RANDOM % 4))
                                    selected_shape = ${ shapes[$random_index] }
                                    echo "______________________________________________________________________"
                                    echo "- - - - Player's Turn - - - -"
                                    echo "Generating a random shape..."
                                    sleep 1
                                    display_shape "$selected_shape"
                                    echo "Enter the shape name (Circle, Star, Umbrella, Triangle) within $time_limit seconds:"
                                    read - t $time_limit player_input

                                    if[-z "$player_input"]; then
                                        echo "Time's up! The correct shape was: $selected_shape"
                                        player_attempts = $((player_attempts - 1))
                                        elif validate_input "$player_input" && ["$player_input" == "$selected_shape"]; then
                                        echo "Correct! Player identified the shape!"
                                        player_score = $((player_score + 10))
                                    else
                                        echo "Wrong guess! The correct shape was: $selected_shape"
                                        player_attempts = $((player_attempts - 1))
                                        fi
                                        fi

                                        if[$computer_attempts - gt 0]; then
                                            random_index = $((RANDOM % 4))
                                            selected_shape = ${ shapes[$random_index] }
                                            computer_guess = ${ shapes[$((RANDOM % 4))] }
                                            echo "________________________________________________________________________"
                                            echo "- - - - Computer's Turn - - - -"
                                            echo "The shape is being generated..."
                                            sleep 1
                                            display_shape "$selected_shape"
                                            echo "Computer guesses: $computer_guess"

                                            if["$computer_guess" == "$selected_shape"]; then
                                                echo "Correct! Computer identified the shape!"
                                                computer_score = $((computer_score + 10))
                                            else
                                                echo "Wrong guess! The correct shape was: $selected_shape"
                                                computer_attempts = $((computer_attempts - 1))
                                                fi
                                                fi

                                                echo "Player Score: $player_score | Computer Score: $computer_score"
                                                echo "Player Attempts: $player_attempts | Computer Attempts: $computer_attempts"
                                                done

                                                gameover
                                                echo "Final Scores - Player: $player_score, Computer: $computer_score"
                                                save_score "Player" $player_score
                                                save_score "Computer" $computer_score

                                                elif["$mode" == "3"]; then
                                                echo "Enter Player 1 Name:"
                                                read player1_name
                                                echo "Enter Player 2 Name:"
                                                read player2_name

                                                score1 = 0
                                                score2 = 0
                                                attempts1 = 3
                                                attempts2 = 3

                                                while[$attempts1 - gt 0] || [$attempts2 - gt 0]; do
                                                    if[$attempts1 - gt 0]; then
                                                        random_index = $((RANDOM % 4))
                                                        selected_shape = ${ shapes[$random_index] }
                                                        echo "______________________________________________________________________"
                                                        echo "- - - - $player1_name's Turn - - - -"
                                                        echo "Generating a random shape..."
                                                        sleep 1
                                                        display_shape "$selected_shape"
                                                        echo "Enter the shape name (Circle, Star, Umbrella, Triangle) within $time_limit seconds:"
                                                        read - t $time_limit input1

                                                        input1_lower = $(echo "$input1" | tr '[:upper:]' '[:lower:]')
                                                        selected_shape_lower = $(echo "$selected_shape" | tr '[:upper:]' '[:lower:]')

                                                        if[-z "$input1_lower"]; then
                                                            echo "Time's up! The correct shape was: $selected_shape"
                                                            attempts1 = $((attempts1 - 1))
                                                            elif validate_input "$input1_lower" && ["$input1_lower" == "$selected_shape_lower"]; then
                                                            echo "Correct!"
                                                            score1 = $((score1 + 10))
                                                        else
                                                            echo "Wrong! The correct shape was: $selected_shape"
                                                            attempts1 = $((attempts1 - 1))
                                                            fi
                                                            fi

                                                            if[$attempts2 - gt 0]; then
                                                                random_index = $((RANDOM % 4))
                                                                selected_shape = ${ shapes[$random_index] }
                                                                echo "______________________________________________________________________"
                                                                echo "- - - - $player2_name's Turn - - - -"
                                                                echo "Generating a random shape..."
                                                                sleep 1
                                                                display_shape "$selected_shape"
                                                                echo "Enter the shape name (Circle, Star, Umbrella, Triangle) within $time_limit seconds:"
                                                                read - t $time_limit input2

                                                                input2_lower = $(echo "$input2" | tr '[:upper:]' '[:lower:]')
                                                                selected_shape_lower = $(echo "$selected_shape" | tr '[:upper:]' '[:lower:]')

                                                                if[-z "$input2_lower"]; then
                                                                    echo "Time's up! The correct shape was: $selected_shape"
                                                                    attempts2 = $((attempts2 - 1))
                                                                    elif validate_input "$input2_lower" && ["$input2_lower" == "$selected_shape_lower"]; then
                                                                    echo "Correct!"
                                                                    score2 = $((score2 + 10))
                                                                else
                                                                    echo "Wrong! The correct shape was: $selected_shape"
                                                                    attempts2 = $((attempts2 - 1))
                                                                    fi
                                                                    fi

                                                                    echo "Scores -> $player1_name: $score1 | $player2_name: $score2"
                                                                    echo "Attempts Left -> $player1_name: $attempts1 | $player2_name: $attempts2"
                                                                    done

                                                                    gameover
                                                                    echo "Final Scores:"
                                                                    echo "$player1_name: $score1"
                                                                    echo "$player2_name: $score2"

                                                                    save_score "$player1_name" $score1
                                                                    save_score "$player2_name" $score2

                                                                    # Determine and display the winner
                                                                    if[$score1 - gt $score2]; then
                                                                        echo "$player1_name wins! 🏆"
                                                                        elif[$score2 - gt $score1]; then
                                                                        echo "$player2_name wins! 🏆"
                                                                    else
                                                                        echo "It's a tie! 🤝"
                                                                        fi

                                                            else
                                                                echo "Invalid mode selected. Please try again."
                                                                fi

                                                                echo ""
                                                                echo "Do you want to play again? (yes/no)"
                                                                read play_again
                                                                if [[ "$play_again" != "yes" && "$play_again" != "y" ]]; then
                                                                    echo "Thanks for playing! Goodbye :)"
                                                                    break
                                                                    fi
                                                                    done
}

# Start the game
dalgona_challenge