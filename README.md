# Marble Board Game

## Overview

Welcome to the Marble Board Game called Pente! This game is designed for two players who strategically place red and green marbles on a 6x6 board, divided into four 3x3 game blocks. The objective is to be the first player to align five marbles in a row.

## Rules

- Player 1 places red marbles, and Player 2 places green marbles. Red is always first.
- To place a marble, use the following format: `block:position rotation`.
  - Example: `2:9 3` means placing a marble in Block 2 at position 9 (bottom right) and rotating Block 3 clockwise.
  - For counterclockwise rotation, add a `+` to the rotation number (e.g., `2:9 3+`).

## Winning

The game ends when a player successfully places five marbles in a row. If a player's move does not result in a win, they must rotate one of the four blocks either clockwise or counterclockwise.

## Example Moves

1. Player 1: `1:5 1` (Place a red marble in Block 1 at position 5 and rotate Block 1 clockwise).
2. Player 2: `3:2 4+` (Place a green marble in Block 3 at position 2 and rotate Block 4 counterclockwise).

## How to Play

1. Clone this repository.
2. Run the game application.
3. Follow the prompt to input your moves using the specified format.
4. Play strategically to achieve five marbles in a row and claim victory!

Enjoy playing the Marble Board Game!
