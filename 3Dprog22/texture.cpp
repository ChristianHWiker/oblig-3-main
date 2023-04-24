#define STB_IMAGE_IMPLEMENTATION
#include <qDebug>
#include <iostream>
#include "texture.h"
#include "logger.h"


Texture::Texture()
{
initializeOpenGLFunctions();
textureID = 0; // texture ID
width = 0; // width and height of texture
height = 0;
bitDepth = 0; // pixel size
fileLocation = "../3Dprog22/container1.jpg"; // where the file is located in your project folder //
//example :: /texture/wood.jpg
}


// pass in the address and filename of your image( jpp, png or other formats) when
//you create an object of texture class
Texture::Texture(char* fileLoc)
{
 initializeOpenGLFunctions();
textureID = 0;
width = 0;
height = 0;
bitDepth = 0;
fileLocation = fileLoc;
}


Texture::~Texture()
{
clearTexture();
}


void Texture::loadTexture()
{
    mLogger = Logger::getInstance();
    initializeOpenGLFunctions();

    //const char* file = fileLocation.c_str;
    unsigned char* texData = stbi_load(fileLocation, &width, &height, &bitDepth, 0);
    std::cout << fileLocation << std::endl;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // S and T are also known as U and V, another name being X and Y
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    if (texData) // If the texture data we provided is valid...
    {
        // ... then load the texture...
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texData);
        glGenerateMipmap(GL_TEXTURE_2D);

    }
    else
    {
        // ... otherwise something went wrong and we need to report it.
        mLogger->logText("Could not load texture image", LogType::REALERROR);
        qDebug() << "yo";
    }
    stbi_image_free(texData);
}


void Texture::useTexture()
{
glActiveTexture(GL_TEXTURE0); // which texture unit to make active in GPU //
//there are 16-32 units //depends on GPUs this can vary
glBindTexture(GL_TEXTURE_2D, textureID); // we bind out texture to a 2D
//texture // here we use that texture ID to bind the texture
}


// reset everything
void Texture::clearTexture()
{
glDeleteTextures(1, &textureID);
textureID = 0;
width = 0;
height = 0;
bitDepth = 0;
fileLocation = "../3Dprog22/container1.jpg";
}
