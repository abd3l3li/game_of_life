# Conway's Game of Life - Interactive Terminal Implementation

A minimalist C implementation of Conway's Game of Life with an interactive drawing interface.

## Table of Contents

- [📋 Overview](#-overview)
- [🔨 Compilation](#-compilation)
- [🚀 Usage](#-usage)
- [🎮 Drawing Controls](#-drawing-controls)
- [🧬 Game of Life Rules](#-game-of-life-rules)
- [📤 Output](#-output)
- [⚙️ Implementation Details](#-implementation-details)
- [💾 Memory Management](#-memory-management)
- [🔢 Return Codes](#-return-codes)
- [📝 Notes](#-notes)

---

## 📋 Overview

This program allows you to draw initial patterns using keyboard controls and then simulates Conway's Game of Life cellular automaton for a specified number of iterations.

---

## 🔨 Compilation

```bash
gcc -o game_of_life game_of_life.c
```

---

## 🚀 Usage

```bash
./game_of_life <width> <height> <iterations>
```

### Parameters

- `width`: Grid width (must be > 0)
- `height`: Grid height (must be > 0)
- `iterations`: Number of generations to simulate (must be ≥ 0)

### Example

```bash
./game_of_life 40 20 100
```

---

## 🎮 Drawing Controls

The program reads commands from standard input to let you draw the initial pattern:

- `w` - Move cursor up
- `s` - Move cursor down
- `a` - Move cursor left
- `d` - Move cursor right
- `x` - Toggle drawing mode (pen up/down)

When drawing mode is active, moving the cursor will place living cells on the grid.

### Drawing Example

```bash
echo "xdddddxsxaaaaxsxdddddx" | ./game_of_life 10 10 5
```

Or use interactive input:
```bash
./game_of_life 30 15 50
# Type your commands, then press Ctrl+D to finish
```

---

## 🧬 Game of Life Rules

The simulation follows the classic Conway's Game of Life rules:

1. Any live cell with 2 or 3 live neighbors survives
2. Any dead cell with exactly 3 live neighbors becomes alive
3. All other cells die or stay dead

---

## 📤 Output

After the specified number of iterations, the program displays the final grid state:
- `0` represents a living cell
- ` ` (space) represents a dead cell

---

## ⚙️ Implementation Details

- Uses two buffers for double-buffering the grid state
- Handles boundary checking to prevent out-of-bounds access
- Memory is dynamically allocated based on grid dimensions
- Cursor starts at position (0, 0)

---

## 💾 Memory Management

The program properly allocates and frees memory for both grid buffers. It returns an error code if memory allocation fails.

---

## 🔢 Return Codes

- `0` - Success
- `1` - Invalid arguments or memory allocation failure

---

## 📝 Notes

- The grid uses zero-based indexing internally
- Neighbor counting considers all 8 adjacent cells (Moore neighborhood)
- The simulation does not wrap around edges (non-toroidal grid)
