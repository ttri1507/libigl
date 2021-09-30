#include <igl/readOFF.h>
#include <igl/opengl/glfw/Viewer.h>
#include "tutorial_shared_path.h"


int main(int argc, char *argv[])
{
  Eigen::MatrixXd vertices;
	Eigen::MatrixXi facets;
	Eigen::MatrixXd C;
  
  // Load a mesh in OFF format
  igl::readOFF("screwdriver.off", vertices, facets);

  // Plot the mesh
  igl::opengl::glfw::Viewer viewer;
  viewer.data().set_mesh(vertices, facets);

  // Use the (normalized) vertex positions as colors
  C = 
    (vertices.rowwise()            - vertices.colwise().minCoeff()).array().rowwise()/
    (vertices.colwise().maxCoeff() - vertices.colwise().minCoeff()).array();

  // Add per-vertex colors
  viewer.data().set_colors(C);

  // Launch the viewer
  viewer.launch();
}
