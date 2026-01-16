#include <iostream>
#include <iomanip>
#include <bitset>
#include <stdint.h>
#include "ALU.h"
#include "globals.h"

using namespace std;
//ALU recevies two 32-bit operands, a 5-bit shift amount, and a 4-bit ALU operation code
//ALU produces a 32-bit result based on the operation code
ALU::ALU() {}
// opcode(6) rs(5) rt(5) rd(5) shamt(5) funct(6)
// R-typ: ADDU, AND, NOR, OR, SLL, SRA, SRL, SUBU, XOR, SLT, SLTU

// opcde(6) rs(5) rt(5) immediate(16)
// I-typ: LUI

// EQ, NEQ는 명령어 타입 아니고 조건 비교용으로 추가한 것임
void ALU::compute(uint32_t operand1, uint32_t operand2, uint32_t shamt, uint32_t aluop, uint32_t *alu_result) {
	switch (static_cast<ALUOp>(aluop))
	{
        case ALU_ADDU:
            // 덧셈 연산, overflow 없음
            *alu_result = operand1 + operand2;
            break;
        case ALU_AND:
            *alu_result = operand1 & operand2;
            break;
             
        case ALU_NOR:
            *alu_result = ~(operand1 | operand2);
            break;
        case ALU_OR:
            *alu_result = operand1 | operand2;
            break;
        case ALU_SLL:
            // 왼쪽 시프트는 어차피 0 채워지는거라 상관 없음
            *alu_result = operand2 << shamt;
            break;
        case ALU_SRA:
            // 오른쪽 산술 시프트는 부호를 맞춰줘야 하기 때문에 int32_t로 캐스팅
            // 실제로는 만약 음수면 제일 왼쪽은 1로 채움 
            // -3은 3을 1의 보수 처리함 -> 0000...0011 -> 1111...1100 + 1 -> 1111...1101
            // 이걸 >>2하면 1111...1111 즉 -1이 됨 
            *alu_result = static_cast<int32_t>(operand2) >> shamt;
            break;
        case ALU_SRL:
            // 오른쪽 논리 시프트는 그냥 0 채워지는거라 상관 없음
            *alu_result = operand2 >> shamt;
            break;
        case ALU_SUBU:
            *alu_result = operand1 - operand2;
            break;
        case ALU_XOR:
            *alu_result = operand1 ^ operand2;
            break;
        case ALU_SLT:
            // 부호 있는 비교기 때문에 둘 다 int32_t로 캐스팅
            *alu_result = static_cast<int32_t>(operand1) < static_cast<int32_t>(operand2) ? 1 : 0;
            break;
        case ALU_SLTU:
            // 파라미터가 애초에 uint32_t이기 때문에 그냥 비교 
            *alu_result = operand1 < operand2 ? 1 : 0;
            break;
        case ALU_EQ:
            *alu_result = operand1 == operand2 ? 1 : 0;
            break;
        case ALU_NEQ:
            *alu_result = operand1 != operand2 ? 1 : 0;
            break;
        case ALU_LUI:
            *alu_result = operand2 << 16;
            break;
            break;
		default:
            break;
	}
}

