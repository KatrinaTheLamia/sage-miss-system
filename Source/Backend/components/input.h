/*nimh-doc
 * Project  : SAGE Miss System
 * File     : %(sage-miss-system-root)s/Source/Backend/Components/input.h
 * Authors  : %(KatrinaTheLamia)a
 * Groups   : %(NIMHLabs)g, %(RaddTeam)g
 * Tags     : c source input remap sage miss-system
 * Purpose  :
 * Create an very basic input device. Can be a pointer, but does not need to 
 * be.
 */

#ifndef __Miss_System_Input__
#define __Miss_System_Input__

/*nimh-doc
 * = Event Type
 * What is the event type here?
 *
 * Right now, we have button up, and button down.
 */
enum smse_event_type { down, up };

/*nimh-doc
 * = Input Event
 *
 * An input event--not much to really be noted here.
 *
 * + button callback, reference to the button being asked for.
 * + Event Type, what type of event is this?
 */
typedef struct {
    smse_button_cb *button;
    smse_event_type type;
} smse_input_event_base smse_input_event;

/*nimh-doc
 * = Poll Input Function
 *
 * Should target a wrapper function that deals with the specific local input.
 */
typedef (smse_input_event*)(poll_input_func)(smse_word);

/*nimh-doc
 * = SMSE Input
 *
 * Grab our input for this function.
 *
 * + Key Id, What key are we doing here?
 * + Poll_Input_Func, the function we use to grab this noise.
 */
typedef struct {
    smse_word key_id;
    smse_poll_function *poll_input_func;
} smse_input_base smse_input;

/*nimh-doc
 * = SMSE Button
 *
 * Our Button information.
 * 
 * + Device Id, Generic Word for this input. Most likely a mask of some kind.
 * + Button Id, Input Identifier. This is for the user interface to make note 
 *              of.
 * + Local Definition, Local definition of the Input.
 */
typedef struct {
    smse_word device_id;
    smse_identifier button_id;
    smse_input local_defintion;
} smse_button_base smse_button;

/*nimh-doc
 * = SMSE Pointer
 *
 * Generic Pointer information for this device. 
 *
 * + Id, a local id reference for this entry. To keep trac of pointer.
 * + X, Domain of the input.
 * + Y, Range of the entry.
 */
typedef struct {
    smse_id id;
    smse_position x, y;
} smse_input_pointer_info_base smse_input_pointer_info;

#endif // Miss_System_Input


