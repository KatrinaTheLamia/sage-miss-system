/*nimh-doc
 * Project : %(sage-miss-system)project
 * File : %(sage-miss-system-source)path/Backend/visual-out.h
 * Licenses : %(sage-miss-system-documentataion)path/License.txt
 * Authors : %(KatrinaTheLamia)author
 * Groups : %(NIMHLabs)group %(RaddTeam)group
 * CREATED : 2009-12-08
 * REVISION :
 * 2009-12-08 Created this file
 * TODO:
 * * nil
 * Purpose :
 * Description of various visual out device components.
 */


#ifndef __SAGE_MISS_SYS_BACKEND_VISUAL_OUT_H__
#define __SAGE_MISS_SYS_BACKEND_VISUAL_OUT_H__

/*nimh-doc
 * Constant : smss_tile_width
 * Description : how many pixels wide our tiles will be.
 * Constant : smss_tile_height
 * Descripton : how many pixels tall our tiles will be.
 */
const unsigned byte smss_tile_width = 8;
const unsigned byte smss_tile_height = 8;

enum smss_overflow { transparent = 0, wrap_around = 1, }

/*nimh-doc
 * Type: smss_[12348(16)]bpp_tile
 * Description: a tile data type
 */
typedef u1B[smss_tile_height] smss_1bpp_tile;
typedef u1B:2[smss_tile_width*smss_tile_height] smss_2bpp_tile;
typedef u1B:3[smss_tile_width*smss_tile_height] smss_3bpp_tile;
typedef u1B:4[smss_tile_width*smss_tile_height] smss_4bpp_tile;
typedef u1B[smss_tile_width*smss_tile_height] smss_8bpp_tile;
typedef u2B[smss_tile_width*smss_tile_height] smss_16bpp_tile;

typedef struct {
    bool hblank_interval_free;
    bool vram_mapping;
    bool force_blank;
} display_control;

typedef struct {
    u4B x, y;
    u1B size, shape;
    u4B rotation, skew;
} smss_oam_description;

typedef struct {
    smss_oam_description info;
    smss_1bpp_tile *start;
} smss_1bpp_oam;

typedef struct {
    u4B loss;
    u4B mask;
    u4B shift;
    u4B value;
} smss_colour;

/* */
typedef struct {
    u8B colour_mode;
    smss_colour red, green, blue, alpha;
} smss_palette;

typedef struct {
    bool has_rotation, has_scale;
    u1B layer_count;
    u4B height, width;
    u4B max_tiles, max_colours, max_palettes;
    smss_display_flags features;
} smss_display_mode;

typedef struct {
    bool vblank, hblank, vcounter;
    bool vblank_enable, hblank_enable, vcounter_enable;
    u4B vcount_setting;
    u1B current_scanline;
} smss_display_info;

typedef struct {
    u1B priority;
    bool is_mosiac;
    smss_overflow overflow;
    smss_tilemap tilemap;
    u4B scrolling_offset;
    /* Rotation stuff */
    u2B fractional_portion;
    u4B integer_portion;
    nimh_sign rot_sign;
} smss_background_control;

smss_1bpp_tile* gen_tile_memory(smss_memsize) {
     return (smss_1bpp_tile*) malloc(to_size_t(smss_memsize));
}
smss_2bpp_tile* gen_tile_memory(smss_memsize) {
     return (smss_2bpp_tile*) malloc(to_size_t(smss_memsize));
}
smss_3bpp_tile* gen_tile_memory(smss_memsize) {
     return (smss_3bpp_tile*) malloc(to_size_t(smss_memsize));
}
smss_4bpp_tile* gen_tile_memory(smss_memsize) {
     return (smss_4bpp_tile*) malloc(to_size_t(smss_memsize));
}
smss_8bpp_tile* gen_tile_memory(smss_memsize) {
     return (smss_8bpp_tile*) malloc(to_size_t(smss_memsize));
}
smss_16bpp_tile* gen_tile_memory(smss_memsize) {
     return (smss_16bpp_tile*) malloc(to_size_t(smss_memsize));
}

SDL_Surface* smss_CreateRGBSurface(smss_target_surface, smss_display_mode, smss_palette);

#endif /* __SAGE_MISS_SYS_BACKEND_VISUAL_OUT_H__ *.
