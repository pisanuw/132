// Exercise 8.16 Solution: ex08_16.cpp
// Simpletron Simulator.
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int SIZE = 100;
const int MAX_WORD = 9999;
const int MIN_WORD = -9999;
const int SENTINEL = -99999;

enum {
  READ = 10, WRITE, LOAD = 20, STORE, ADD = 30, SUBTRACT,
  DIVIDE, MULTIPLY, BRANCH = 40, BRANCHNEG, BRANCHZERO, HALT
};

// validate
bool validWord(int word) {
  return word >= MIN_WORD && word <= MAX_WORD;
}

void load(int loadMemory[SIZE], const string &filename) {
  ifstream infile(filename);
  if (!infile.is_open()) {
    cout << "Could not open " << filename << endl;
    return;
  }
  int instruction;
  int i = 0; // instruction location in memory
  int discard_memory_address;
  string discard_comments;
  infile >> discard_memory_address >> instruction;
  getline(infile, discard_comments);
  while (instruction != SENTINEL) {
//    cout << "Memory: " << discard_memory_address
//         << " instruction: " << instruction
//         << " comments: " << discard_comments << endl;
    if (!validWord(instruction)) {
      cout << "Number out of range. " << instruction << endl;
      return;
    } else {
      loadMemory[i++] = instruction;
    }
    infile >> discard_memory_address >> instruction;
    getline(infile, discard_comments);
  }
}

void readCommand(int memory[SIZE], int operand) {
  cout << "Enter a number to be stored at " << operand << ": ";
  int num;
  cin >> num;
  // TODO store it in memory location
}

void execute(int memory[SIZE]) {
  int instructionNumber = 0;
  int opcode = memory[instructionNumber] / 100;
  int operand = memory[instructionNumber] % 100;
  while (opcode != HALT) {
    cout << setfill('0');
    cout << "AT: " << setw(2) << instructionNumber;
    cout << "\texecuting:\t" << memory[instructionNumber] << endl;
    switch(opcode) {
      case READ: readCommand(memory, operand); break;
      case WRITE: break;
      case LOAD: break;
      case STORE: break;
      case ADD: break;
      case SUBTRACT: break;
      case DIVIDE: break;
      case MULTIPLY: break;
      case BRANCH: break;
      case BRANCHNEG: break;
      case BRANCHZERO: break;
      default:
        cout << "Unrecognized command: " << opcode << endl;
    }
    instructionNumber++;
    opcode = memory[instructionNumber] / 100;
    operand = memory[instructionNumber] % 100;
  }
}

// print out name and content of each register and memory
void dump(int memory[SIZE]) {
  cout << "\n\nMEMORY:\n";
  cout << setfill(' ') << setw(3) << ' ';
  // print header
  for (int i = 0; i <= 9; ++i) {
    cout << setw(5) << i << ' ';
  }
  // memory
  for (int i = 0; i < SIZE; ++i) {
    if (i % 10 == 0) {
      cout << endl << setw(2) << i << ' ';
    }
    cout << internal << setw(5) << setfill('0')
         << memory[i] << ' ' << internal;
  }
  cout << endl;
}

int main() {
  int memory[SIZE]{0};

  load(memory, "sml1.txt");
  execute(memory);
  dump(memory);
}