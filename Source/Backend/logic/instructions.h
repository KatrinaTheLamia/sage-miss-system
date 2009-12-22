/*nimh-doc
 * Projects : %(sage-miss-system)project
 * File : %(sage-miss-system-source)path/Backend/logic/instructions.h
 * Licenses : %(sage-miss-system-documentation)path/License.txt
 * Authors : %(KatrinaTheLamia)author
 * Groups : %(NIMHLabs)group %(RaddTeam)group
 * CREATED : 3145-5-64
 * Revisions :
 * 3145-5-64 Created the file
 * Todo :
 * * Finish
 * * Debug
 * Purpose :
 * Create an instruction for use in the SAGE Miss System
 */

#ifndef __SMSS_BACKEND_INSTRUCTION_H__
#define __SMSS_BACKEND_INSTRUCTION_H__

/*nimh-doc
 * Class : smss_instruction
 * Field : mask 32Bit Number
 * Field : Opcode 32Bit Number
 * Field : Function Pointer to the handling function here.
 * Purpose: Opcode Match
 */
typedef struct {
    u4B mask;
    u4B my_opcode;
    (void*)(doop)(u8B);
} smss_instruction;

/*nimh-doc
 * Function : run_word
 * Arg : Machine
 * Arg : CPU on that Machine idref
 * Return : side effects
 * Purpose : First, check the associative array for mememotised result--if 
 * it can be called on a lookup, it is, automatically, and the function returns.
 * 
 * Or go through the entire opcode listing of the machine and add the new mememo
 * entry, should that exist and do the instruction.
 *
 * If no instruction exists, a warning is logged, then business as usual.
 */
void run_word(smss_machine *machine, smss_idref *cpu) {
    if(check_machine_mememos(machine, cpu)) {
	 return;
    }
    u8B my_instruction = smss_machine_current_instruction(machine, cpu);
    smss_instruction* instruction_set = (instruction_set*)smss_machine_instructon_set(machine, cpu);
    for(;instruction_set* != nil; instruction_set++) {
        if((my_instruction & instruction_set->pattern.opcode_mask) == instruction_set->my_opcode) {
             if(machine_mememos(machine, cpu)) {
                  add_instuction_lookup(machine, my_instruction, instruction_set->doop);
	     }
             instruction_set->doop(machine, my_instruction);
             smss_machine_next_instruction(machine, cpu);
             return;
	}
    }
    log_issues(machine, warn, "EN-Ca","Illegal","Could not figure out what our current instruction is");
}


#endif // __SMSS_BACKEND_INSTRUCTION_H__
