#ifndef LEARNOPENGL_SHADER_HPP
#define LEARNOPENGL_SHADER_HPP

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
public:
        // the program ID
        unsigned int ID;

        // Constructor reads and builds the shader.
        Shader(const char* vertexPath, const char* fragmentPath);
        // Use/Activate the shader.
        void use();
        // Utility uniform functions.
        void setBool(const std::string &name, bool value) const;
        void setInt(const std::string &name, int value) const;
        void setFloat(const std::string &name, float value) const;
};


#endif //LEARNOPENGL_SHADER_HPP
