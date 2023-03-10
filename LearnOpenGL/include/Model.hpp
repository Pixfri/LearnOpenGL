#ifndef LEARNOPENGL_MODEL_HPP
#define LEARNOPENGL_MODEL_HPP

#include <assimp/mesh.h>
#include <assimp/scene.h>
#include <assimp/material.h>
#include <string>
#include <vector>

#include "Shader.hpp"
#include "Mesh.hpp"

class Model {
public:
        Model(std::string path);

        void Draw(Shader &shader);

private:
        // model data
        std::vector<Mesh> meshes;
        std::string directory;
        std::vector<Texture> textures_loaded;

        void loadModel(std::string path);
        void processNode(aiNode *node, const aiScene *scene);
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);
        std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type,
                                                  std::string typeName);
        unsigned int TextureFromFile(const char* path, const std::string &directory, bool gamma = false);
};


#endif //LEARNOPENGL_MODEL_HPP
