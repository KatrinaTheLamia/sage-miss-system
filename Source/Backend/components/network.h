/*nimh-doc
 * Project  : SAGE Miss System
 * File     : %(sage-miss-system-root)s/Source/Backend/Components/network.h
 * Authors  : %(KatrinaTheLamia)u
 * Groups   : %(NIMHLabs)g %(RaddTeam)g
 * Tags     : emulation input output network intelligent
 * Created  : &Date(20091204)
 * Changes  :
 * * &Date(20091204) Created this file.
 * Todo     :
 * * Debug
 * * Function Prototypes to use the network device
 * Purpose  :
 * Setup a form of network based input.
 */

#ifndef __SAGE_BACKEND_NETWORK_INPUT_H__
#define __SAGE_BACKEND_NETWORK_INPUT_H__

typedef smse_bool smse_updown;

enum smse_network_mode { loopback, broadcast };
enum smse_address_mode { unicast, multicast};

/*nimh-doc
 * = Address Protocol
 *
 * What Protocol are we using? Currently recognising ipv4, ipv6, MAC, sip, 
 * netbios and catnip.
 */
enum smse_protocal { ipv4, ipv6, mac, sip, netbios, catnip };

/*nimh-doc
 * = Packet
 *
 * Not much here yet. Data is the word sent. This can be a controller input 
 * or a connector port. There is not the type for a device socket, like the 
 * network hardware on a NDS, Tegra System, PSP, Gamecube, Wii, Dreamcast, 
 * Playstation 2, Playstation 3, XBox, XBox 360, etc.
 */
typedef struct {
    smse_word data;
    smse_checksum check;
} smse_network_packet_base smse_network_packet;

/*nimh-doc
 * = Network Address
 *
 * Network Address type. Mostly for noting who we are talking to.
 */
typedef struct {
    smse_protocal proto;
    smse_word *network_addr;
} smse_network_address_base smse_network_address;

/*nimh-doc
 * = Network State
 *
 * The state of the network
 */
typedef struct {
    smse_updown updown;
    smse_network_mode mode;
    smse_address_mode mode;
} smse_network_state_base smse_network_state;

/*nimh-base
 * = Network Stats
 *
 * Network statistics struct.
 */
typedef struct {
    smse_whole_number packet, errors, dropped, overruns, frame, carrier, collisions, queue_length, bytes;
} smse_network_stats_base smse_network_stats;

/*nimh-doc
 * = Network Device
 *
 * Network Device type
 */
typedef struct {
    smse_word mtu, metric;
    smse_network_state State;
    smse_network_address MAC, software;
    smse_string scope;
    smse_network_stats recieved, transfered;
} smse_network_device_base smse_network_device;

#endif // __SAGE_BACKEND_NETWORK_INPUT_H__
