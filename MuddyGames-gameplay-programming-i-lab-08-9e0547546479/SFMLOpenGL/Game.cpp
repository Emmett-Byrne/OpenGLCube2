#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	InitVertexes();

	
}

Game::~Game() {}


void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

void Game::initialize()
{
	isRunning = true;

	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glTranslatef(0.0f, 0.0f, -10.0f);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	processEvents();

	for (int i = 0; i < 8; i++)
	{
		vertex[i] = MyMatrix3::translation(transX, transY) * vertex[i];

		vertex[i] = MyMatrix3::rotationX(angleX * 0.0174533) * vertex[i];
		vertex[i] = MyMatrix3::rotationY(angleY * 0.0174533) * vertex[i];

		vertex[i] = MyMatrix3::scale(scaleX, scaleY) * vertex[i];
	}

	for (int i = 0; i < 8; i++)
	{
		vertices[i * 3] = vertex[i].X();
		vertices[i * 3 + 1] = vertex[i].Y();
		vertices[i * 3 + 2] = vertex[i].Z();
	}


	cout << "Update up" << endl;
}

void Game::render()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing" << endl;

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);

	//glDrawArrays(GL_TRIANGLES, 0, 3);

	glDrawElements(GL_TRIANGLES, 32, GL_UNSIGNED_INT, &vertex_index);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

void Game::InitVertexes()
{
	vertex[0] = MyVector3D(1.0f, 1.0f, 1.0f); //front top right
	vertex[1] = MyVector3D(-1.0f, 1.0f, 1.0f); //front bottom right
	vertex[2] = MyVector3D(-1.0f, -1.0f, 1.0f); //front bottom left
	vertex[3] = MyVector3D(1.0f, -1.0f, 1.0f); //front top left
	vertex[4] = MyVector3D(1.0f, 1.0f, -1.0f); //back top right
	vertex[5] = MyVector3D(-1.0f, 1.0f, -1.0f); //back bottom right
	vertex[6] = MyVector3D(-1.0f, -1.0f, -1.0f); //back bottom left
	vertex[7] = MyVector3D(1.0f, -1.0f, -1.0f); //back top left
}

void Game::processEvents()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		angleX += 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		angleX -= 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		angleY += 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		angleY -= 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		scaleX += 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		scaleX -= 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		scaleY += 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		scaleY -= 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		transX += 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		transX -= 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
	{
		transY += 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		transY -= 0.01;
	}
}

