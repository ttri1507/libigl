#include <igl/readOFF.h>
#include <igl/opengl/glfw/Viewer.h>
#include "tutorial_shared_path.h"


int main(int argc, char *argv[])
{
  Eigen::MatrixXd vertices;
	Eigen::MatrixXi facets;
  // Load a mesh in OFF format
  igl::readOFF("/bunny.off", vertices, facets);

  // Plot the mesh
  igl::opengl::glfw::Viewer viewer;
  viewer.data().set_mesh(vertices, facets);
  viewer.launch();
}
