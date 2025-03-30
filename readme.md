# Battleship Game in C++

## Overview
This is a simple console-based Battleship game written in C++. The game allows a player to place ships on a 10x10 grid and engage in a turn-based battle against a computer opponent. The objective is to destroy all enemy ships before they destroy yours.

## Features
- Selectable difficulty levels (Easy, Medium, Hard)
- Manual ship placement with orientation selection (horizontal/vertical)
- Randomized ship placement for the computer opponent
- Turn-based gameplay with visual indicators for hits and misses
- Basic AI for the computer opponent
- Simple console-based UI

## How to Play
1. Run the program in a C++-supported terminal.
2. Choose a difficulty level.
3. Place your ships by specifying their orientation and coordinates.
4. Take turns attacking the opponent's grid.
5. The first to destroy all enemy ships wins.

## Rules
1. Each player has a 10x10 battlefield.
2. Players place their ships before the battle begins.
3. The available ships are:
   - Aircraft Carrier (5 units long)
   - Battleship (4 units long)
   - Destroyer (3 units long)
   - Corvette (2 units long)
4. During your turn, enter coordinates to attack the enemy grid.
5. A hit is marked as 'H', and a miss is marked as '*'.
6. Destroy all enemy ships to win.

## Installation & Compilation
### Prerequisites
- A C++ compiler (GCC, MinGW, MSVC, or Clang)

### Compilation
Use the following command to compile the program:
```
g++ battleship.cpp -o battleship
```

### Running the Program
```
./battleship
```

## Credits
Developed by:
- Sufyan Malik
- M. Usman Aziz

## License
This project is for educational purposes and is open-source under the MIT License.

