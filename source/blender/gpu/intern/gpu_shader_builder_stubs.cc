/* SPDX-License-Identifier: GPL-2.0-or-later
 * Copyright 2021 Blender Foundation. All rights reserved. */

/** \file
 * \ingroup gpu
 *
 * Stubs to reduce linking time for shader_builder.
 */

#include "BLI_utildefines.h"

#include "IMB_imbuf.h"
#include "IMB_imbuf_types.h"

#include "BKE_attribute.h"
#include "BKE_customdata.h"
#include "BKE_global.h"
#include "BKE_material.h"
#include "BKE_mesh.h"
#include "BKE_node.h"
#include "BKE_paint.h"
#include "BKE_pbvh.h"
#include "BKE_subdiv_ccg.h"

#include "DNA_userdef_types.h"

#include "NOD_shader.h"

#include "DRW_engine.h"

#include "bmesh.h"

#include "UI_resources.h"

extern "C" {

Global G;
UserDef U;

/* -------------------------------------------------------------------- */
/** \name Stubs of BLI_imbuf_types.h
 * \{ */

void IMB_freeImBuf(ImBuf * /*ibuf*/)
{
  BLI_assert_unreachable();
}

struct ImBuf *IMB_allocImBuf(unsigned int /*x*/,
                             unsigned int /*y*/,
                             unsigned char /*planes*/,
                             unsigned int /*flags*/)
{
  BLI_assert_unreachable();
  return nullptr;
}

/** \} */

/* -------------------------------------------------------------------- */
/** \name Stubs of UI_resources.h
 * \{ */

void UI_GetThemeColor4fv(int /*colorid*/, float UNUSED(col[4]))
{
  BLI_assert_unreachable();
}

void UI_GetThemeColor3fv(int /*colorid*/, float UNUSED(col[3]))
{
  BLI_assert_unreachable();
}

void UI_GetThemeColorShade4fv(int /*colorid*/, int /*offset*/, float UNUSED(col[4]))
{
  BLI_assert_unreachable();
}

void UI_GetThemeColorShadeAlpha4fv(int /*colorid*/,
                                   int /*coloffset*/,
                                   int /*alphaoffset*/,
                                   float UNUSED(col[4]))
{
  BLI_assert_unreachable();
}
void UI_GetThemeColorBlendShade4fv(
    int /*colorid1*/, int /*colorid2*/, float /*fac*/, int /*offset*/, float UNUSED(col[4]))
{
  BLI_assert_unreachable();
}

void UI_GetThemeColorBlend3ubv(int /*colorid1*/,
                               int /*colorid2*/,
                               float /*fac*/,
                               uchar UNUSED(col[3]))
{
  BLI_assert_unreachable();
}

void UI_GetThemeColorShadeAlpha4ubv(int /*colorid*/,
                                    int /*coloffset*/,
                                    int /*alphaoffset*/,
                                    uchar UNUSED(col[4]))
{
  BLI_assert_unreachable();
}

/** \} */

/* -------------------------------------------------------------------- */
/** \name Stubs of BKE_attribute.h
 * \{ */

eAttrDomain BKE_id_attribute_domain(const struct ID * /*id*/,
                                    const struct CustomDataLayer * /*layer*/)
{
  return ATTR_DOMAIN_AUTO;
}

/** \} */

/* -------------------------------------------------------------------- */
/** \name Stubs of BKE_paint.h
 * \{ */
bool paint_is_face_hidden(const struct MLoopTri * /*lt*/, const bool * /*hide_poly*/)
{
  BLI_assert_unreachable();
  return false;
}

void BKE_paint_face_set_overlay_color_get(const int /*face_set*/,
                                          const int /*seed*/,
                                          uchar UNUSED(r_color[4]))
{
  BLI_assert_unreachable();
}

bool paint_is_grid_face_hidden(const uint * /*grid_hidden*/,
                               int /*gridsize*/,
                               int /*x*/,
                               int /*y*/)
{
  BLI_assert_unreachable();
  return false;
}

/** \} */

/* -------------------------------------------------------------------- */
/** \name Stubs of BKE_mesh.h
 * \{ */
void BKE_mesh_calc_poly_normal(const struct MPoly * /*mpoly*/,
                               const struct MLoop * /*loopstart*/,
                               const struct MVert * /*mvarray*/,
                               float UNUSED(r_no[3]))
{
  BLI_assert_unreachable();
}

void BKE_mesh_looptri_get_real_edges(const struct MEdge * /*edges*/,
                                     const struct MLoop * /*loops*/,
                                     const struct MLoopTri * /*looptri*/,
                                     int UNUSED(r_edges[3]))
{
  BLI_assert_unreachable();
}

/** \} */

/* -------------------------------------------------------------------- */
/** \name Stubs of BKE_material.h
 * \{ */

void BKE_material_defaults_free_gpu()
{
  /* This function is reachable via GPU_exit. */
}

/** \} */

/* -------------------------------------------------------------------- */
/** \name Stubs of BKE_customdata.h
 * \{ */

int CustomData_get_offset(const struct CustomData * /*data*/, int /*type*/)
{
  BLI_assert_unreachable();
  return 0;
}

int CustomData_get_named_layer_index(const struct CustomData * /*data*/,
                                     int /*type*/,
                                     const char * /*name*/)
{
  return -1;
}

int CustomData_get_active_layer_index(const struct CustomData * /*data*/, int /*type*/)
{
  return -1;
}

int CustomData_get_render_layer_index(const struct CustomData * /*data*/, int /*type*/)
{
  return -1;
}

bool CustomData_has_layer(const struct CustomData * /*data*/, int /*type*/)
{
  return false;
}

void *CustomData_get_layer_named(const struct CustomData * /*data*/,
                                 int /*type*/,
                                 const char * /*name*/)
{
  return nullptr;
}

void *CustomData_get_layer(const struct CustomData * /*data*/, int /*type*/)
{
  return nullptr;
}

/** \} */

/* -------------------------------------------------------------------- */
/** \name Stubs of BKE_pbvh.h
 * \{ */

int BKE_pbvh_count_grid_quads(BLI_bitmap ** /*grid_hidden*/,
                              const int * /*grid_indices*/,
                              int /*totgrid*/,
                              int /*gridsize*/,
                              int /*display_gridsize*/)
{
  BLI_assert_unreachable();
  return 0;
}

/** \} */

/* -------------------------------------------------------------------- */
/** \name Stubs of BKE_subdiv_ccg.h
 * \{ */
int BKE_subdiv_ccg_grid_to_face_index(const SubdivCCG * /*subdiv_ccg*/, const int /*grid_index*/)
{
  BLI_assert_unreachable();
  return 0;
}

/** \} */

/* -------------------------------------------------------------------- */
/** \name Stubs of BKE_node.h
 * \{ */
void ntreeGPUMaterialNodes(struct bNodeTree * /*localtree*/, struct GPUMaterial * /*mat*/)
{
  BLI_assert_unreachable();
}

struct bNodeTree *ntreeLocalize(struct bNodeTree * /*ntree*/)
{
  BLI_assert_unreachable();
  return nullptr;
}

void ntreeFreeLocalTree(struct bNodeTree * /*ntree*/)
{
  BLI_assert_unreachable();
}

/** \} */

/* -------------------------------------------------------------------- */
/** \name Stubs of bmesh.h
 * \{ */
void BM_face_as_array_vert_tri(BMFace * /*f*/, BMVert *UNUSED(r_verts[3]))
{
  BLI_assert_unreachable();
}
/** \} */

/* -------------------------------------------------------------------- */
/** \name Stubs of DRW_engine.h
 * \{ */
void DRW_deferred_shader_remove(struct GPUMaterial * /*mat*/)
{
  BLI_assert_unreachable();
}

void DRW_cdlayer_attr_aliases_add(struct GPUVertFormat * /*format*/,
                                  const char * /*base_name*/,
                                  const struct CustomData * /*data*/,
                                  const struct CustomDataLayer * /*cl*/,
                                  bool /*is_active_render*/,
                                  bool /*is_active_layer*/)
{
}

/** \} */
}
