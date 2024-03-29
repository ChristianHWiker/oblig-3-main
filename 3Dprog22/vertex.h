#ifndef VERTEX_H
#define VERTEX_H

#include "QVector3D"
#include <iostream>
#include <fstream>


class Vertex {
   //! Overloaded ostream operator which writes all vertex data on an open textfile stream
   friend std::ostream& operator<< (std::ostream&, const Vertex&);


   //! Overloaded ostream operator which reads all vertex data from an open textfile stream
   friend std::istream& operator>> (std::istream&, Vertex&);


private:


public:
   Vertex();
   Vertex(float x, float y, float z, float r, float g, float b, float s, float t);
   Vertex(float x, float y, float z, float r, float g, float b);
   Vertex(float x, float y, float z);
   QVector3D getXYZ();

   float m_xyz[3];       	// position i 3D
   float m_normal[3];    // normal in 3D or rgb colors
   float m_st[2];        	// texture coordinates if used

};

#endif // VERTEX_H
