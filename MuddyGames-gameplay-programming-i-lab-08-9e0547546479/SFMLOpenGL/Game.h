#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <MyVector3D.h>
#include <MyMatrix3.h>

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();

	void InitVertexes();
	void processEvents();
	Clock clock;
	Time elapsed;

	float vertices[24];
	float colors[24] = { 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f };
	unsigned int vertex_index[36] = { 0, 1, 2, 0, 2, 3,
									  4, 5, 6, 4, 6, 7,
									  4, 5, 1, 4, 1, 0,
									  7, 6, 2, 7, 2, 3,
									  4, 0, 3, 4, 3, 7,
									  1, 5, 6, 1, 6, 2 };

	float angleX = 0.0f;
	float angleY = 0.0f;

	float scaleX = 100;
	float scaleY = 100;

	float transX = 0.0f;
	float transY = 0.0f;

	MyVector3D vertex[8];
};