//
//  NESCGLFilter.hpp
//  NESImage
//
//  Created by chen on 2018/12/24.
//  Copyright © 2018年 chen. All rights reserved.
//

#ifndef NESCGLFilter_hpp
#define NESCGLFilter_hpp

#include <stdio.h>
#include "NESCGLTypes.hpp"
#include "NESCGL.hpp"
#include "NESCGLProgram.hpp"
#include "NESCGLFramebuffer.hpp"
#include "NESCGLTexture.hpp"

namespace NESCGL {
    
    extern const char* default_glprogram_vertex_shader;
    extern const char* default_glprogram_fragment_shader;
        
    class NESCGLFilter{
        
        const NESfloat default_vertices[8] =
        {
            -1.0f,  -1.0,
            1.0f,   -1.0,
            -1.0f,  1.0f,
            1.0f,   1.0f
        };
        const NESfloat default_tex_coordinates[8] =
        {
            0.0f,   0.0f,
            1.0f,   0.0,
            0.0f,   1.0f,
            1.0f,   1.0f
        };
        
    public:
        NESCGLFilter(void);//use method below
        NESCGLFilter(const NESchar* ver, const NESchar* fra);//vertex shader, fragment shader
        virtual ~NESCGLFilter(void);
        
    protected:
        void create_program(const NESchar* ver, const NESchar* fra);
        void create_gl_buffer();
        
        void delete_program();
        void delete_gl_buffer();
        
    public:
        
        NESCGLProgram* program;
        NESuint vertex_buffer;
        NESuint coordinate_buffer;
        
        NESint gl_vertex_id;
        NESint gl_tex_coordinate_id;
        NESint gl_input_texture_id;
        
    public:
        void render(NESCGLFramebuffer* renderBuffer, NESRecti* viewport, NESCGLTexture* inputTexture);
        
        
    };
    
    
}//namespace NESCGL

#endif /* NESCGLFilter_hpp */
