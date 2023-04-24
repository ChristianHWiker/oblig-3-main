#version 410 core

/*in vec4 color;              //color received from the pipeline (and vertex shader)
out vec4 fragmentColor; */    //color sent to fragment on screen
//glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
//glm::vec3 toyColor(1.0f, 0.5f, 0.31f);
//glm::vec3 result = lightColor * toyColor; // = (1.0f, 0.5f, 0.31f);

//void main() {
//  fragmentColor = color;   //color given to current fragment (pixel)
//  float ambientStrength = 0.1;

//}

in vec4 color;              //color received from the pipeline (and vertex shader)
out vec4 fragmentColor;     //color sent to fragment on screen

uniform sampler2D textureSampler;

void main() {
   fragmentColor = color;   //color given to current fragment (pixel)
}
