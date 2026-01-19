`timescale 1ns / 1ps 
// #0.5는 0.5ns임. 1ns는 time unit이고, 1ps는 time precision으로 시뮬레이터가 시간을 1ps 단위로 표현/반올림 할 수 있다는 뜻
`include "GLOBAL.v"

// this is a combinational logic
module ALU(
		input [31:0]		operand1,
		input [31:0]		operand2,
		input [4:0]			shamt,
		input [3:0]			funct,
		output reg [31:0]	alu_result
	);
	
	// FIXME
	always @(*) begin
		alu_result = 0;
		case (funct)
			`ALU_ADDU:
				//cpp에서는 *alu_result=op1+operand2
				alu_result=operand1+operand2;
			`ALU_AND :
				alu_result=operand1&operand2;
				
			`ALU_NOR :
				alu_result=~(operand1|operand2);
				
			`ALU_OR  :
				alu_result=operand1|operand2;
				
			`ALU_SLL :
				// logically shift left 
				alu_result=operand2<<shamt;
				
			`ALU_SRA :
				alu_result=$signed(operand2)>>>shamt;
				
			`ALU_SRL :
				alu_result=operand2>>shamt;
				
			`ALU_SUBU:
				alu_result=operand1-operand2;
				
			`ALU_XOR :
				alu_result=operand1^operand2;
				
			`ALU_SLT :
				alu_result= ($signed(operand1) < $signed(operand2));
				
			`ALU_SLTU:
				alu_result=(operand1 < operand2);
				
			`ALU_EQ  :
				alu_result=(operand1 == operand2);
				
			`ALU_NEQ :
				alu_result=(operand1 != operand2);
				
			`ALU_LUI :
				alu_result=operand2<<16;
				
		endcase
	end
endmodule
