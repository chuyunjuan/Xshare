/*
 * Cairo Background renderer
 * Render all those things not supported as Image, with Cairo
 *
 * Copyright (C) 2012 Lu Wang <coolwanglu@gmail.com>
 */


#ifndef CAIRO_BACKGROUND_RENDERER_H__
#define CAIRO_BACKGROUND_RENDERER_H__

#include <CairoOutputDev.h>

#include "Param.h"

namespace pdf2htmlEX {

// Based on BackgroundRenderer from poppler
class CairoBackgroundRenderer : public CairoOutputDev 
{
public:
  CairoBackgroundRenderer(const Param * param)
      :CairoOutputDev()
      , param(param)
  { }

  virtual ~CairoBackgroundRenderer() { }
  
  virtual void drawChar(GfxState *state, double x, double y,
      double dx, double dy,
      double originX, double originY,
      CharCode code, int nBytes, Unicode *u, int uLen);

  void render_page(PDFDoc * doc, int pageno, const std::string & filename);

protected:
  const Param * param;
};

}

#endif //CAIRO_BACKGROUND_RENDERER_H__
