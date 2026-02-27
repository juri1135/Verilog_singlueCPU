#include <iostream>
#include <iomanip>
#include <bitset>
#include <stdint.h>
#include "ALU.h"
#include "globals.h"

using namespace std;

ALU::ALU() {}

void ALU::compute(uint32_t operand1, uint32_t operand2,
				uint32_t shamt, uint32_t aluop, uint32_t *alu_result) {
	switch (static_cast<ALUOp>(aluop))
	{
        case ALU_ADDU:
        case ALU_AND:
        case ALU_NOR:
        case ALU_OR:
        case ALU_SLL:
        case ALU_SRA:
        case ALU_SRL:
        case ALU_SUBU:
        case ALU_XOR:
        case ALU_SLT:
        case ALU_SLTU:
        case ALU_EQ:
        case ALU_NEQ:
        case ALU_LUI:
		default:
	}
}

