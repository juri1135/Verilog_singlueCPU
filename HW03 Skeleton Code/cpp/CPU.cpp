#include <iomanip>
#include <iostream>
#include "CPU.h"
#include "globals.h"

#define VERBOSE 0

using namespace std;

CPU::CPU() {}

// Reset stateful modules
void CPU::init(string inst_file) {
	// Initialize the register file
	rf.init(false);
	// Load the instructions from the memory
	mem.load(inst_file);
	// Reset the program counter
	PC = 0;

	// Set the debugging status
	status = CONTINUE;
}

// This is a cycle-accurate simulation
uint32_t CPU::tick() {
	// These are just one of the implementations ...

	// wire for instruction
	uint32_t inst;

	// parsed & control signals (wire)
	CTRL::ParsedInst parsed_inst;
	CTRL::Controls controls;
	uint32_t ext_imm;

	// Default wires and control signals
	uint32_t rs_data, rt_data;
	uint32_t wr_addr;
	uint32_t wr_data;
	uint32_t operand1;
	uint32_t operand2;
	uint32_t alu_result;

	// PC_next
	uint32_t PC_next;

	// You can declare your own wires (if you want ...)
	uint32_t mem_data;
	...


	// Access the instruction memory
	mem.imemAccess(??);
	if (status != CONTINUE) return 0;
	
	// Split the instruction & set the control signals
	ctrl.splitInst(??);
	ctrl.controlSignal(??);
	ctrl.signExtend(??);
	if (status != CONTINUE) return 0;

	operand1 = ??;
	operand2 = ??;

	alu.compute(??);
	if (status != CONTINUE) return 0;

	// MEM (+PC Update)
	mem.dmemAccess(??);
	if (status != CONTINUE) return 0;

	// Update the PC
	PC_next = ??;

	// WB
	wr_addr = ??;
	wr_data = ??;

	// Update the PC register last ...
	PC = PC_next;

	return 1;
}

