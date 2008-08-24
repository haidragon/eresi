/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_nge_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_NGE_PS;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
