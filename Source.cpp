#include <SFML/Graphics.hpp>
#include <time.h>
#include <vector>
#include <iostream>
#include <cmath>
using namespace sf;
using namespace std;

class grid {
public:
	int side;
	RectangleShape line;
	Vector2f pozicija;

	grid(int i);
	grid(int j, int k);
	void draw(RenderWindow& window);
};

grid::grid(int i) {
	side = 25;
	pozicija = Vector2f(i * side, 0);
	line.setSize(Vector2f(5, 805));
	line.setPosition(pozicija);
	line.setFillColor(Color(128, 128, 128));
}

grid::grid(int i, int k) {
	side = 25;
	pozicija = Vector2f(0, i * side);
	line.setSize(Vector2f(1205, 5));
	line.setPosition(pozicija);
	line.setFillColor(Color(128, 128, 128));
}

void grid::draw(RenderWindow& window) {
	window.draw(line);
}

class kocka {
public:
	kocka(int x, int y);
	RectangleShape kockic;
	Vector2f poz;
	void draw(RenderWindow& window);
};

kocka::kocka(int x, int y) {
	kockic.setSize(Vector2f(20, 20));
	poz = Vector2f(5 + x * 25, 5 + y * 25);
	kockic.setPosition(poz);
}

void kocka::draw(RenderWindow& window) {
	window.draw(kockic);
}

void Paintwhite(int x, int y, int gridstatus[48][33]);
void gridpaint(int gridstatus[48][33], vector<kocka>& grid);
void cycle(int gridstatus[48][33]);

int main()
{
	RenderWindow window(VideoMode(1205, 805), "Game of life");
	window.setFramerateLimit(60);

	bool ponavljanje = false;
	int dellayclick = 0;
	int Mousex, Mousey;
	int gridstatus[48][33] = { 0 };

	vector<grid> gridd;
	vector<kocka> kocgrid;

	for (int i = 0; i < 49; i++)
		gridd.push_back(grid(i));
	for (int i = 0; i < 33; i++)
		gridd.push_back(grid(i, 0));

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == event.Closed)
				window.close();
		}
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			Mousex = Mouse::getPosition(window).x;
			Mousey = Mouse::getPosition(window).y;
			cout << Mousex << endl;
			cout << Mousey << endl;
			Paintwhite(Mousex, Mousey, gridstatus);
		}
		gridpaint(gridstatus, kocgrid);

		if (Keyboard::isKeyPressed(Keyboard::Space) && dellayclick > 20)
		{
			if (ponavljanje == false)
			{
				ponavljanje = true;
				dellayclick = 0;
			}
			else
			{
				ponavljanje = false;
				dellayclick = 0;
			}
		}
		if (ponavljanje == true)
			cycle(gridstatus);

		if (dellayclick < 22)
			dellayclick++;

		window.clear();
		for (auto& kruzic : gridd)
			kruzic.draw(window);
		for (auto& kruzic : kocgrid)
			kruzic.draw(window);
		window.display();

	}

	return 0;
}

void Paintwhite(int x, int y, int gridstatus[48][33])
{
	int x1 = x / 25;
	int y1 = y / 25;
	int xx = ceil(x1);
	int yy = ceil(y1);
	if (x > (xx) * (25) + 5)
		gridstatus[xx][yy] = 1;
}

void gridpaint(int gridstatus[48][33], vector<kocka>& grid)
{
	grid.clear();
	for (int i = 0; i < 48; i++)
	{
		for (int j = 0; j < 33; j++)
		{
			if (gridstatus[i][j] == 1)
			{
				grid.push_back(kocka(i, j));
			}
		}
	}
}

void cycle(int gridstatus[48][33])
{
	int newGrid[48][33] = { 0 };
	for (int i = 0; i < 48; i++)
	{
		for (int j = 0; j < 33; j++)
		{
			int sum = 0;
			for (int k = i - 1; k <= i + 1; k++)
			{
				for (int z = j - 1; z <= j + 1; z++)
				{
					if (k >= 0 && k < 48 && z >= 0 && z < 33)
						sum += gridstatus[k][z];
				}
			}

			sum -= gridstatus[i][j];

			if (gridstatus[i][j] == 1 && (sum < 2 || sum > 3))
				newGrid[i][j] = 0;
			else if (gridstatus[i][j] == 0 && sum == 3)
				newGrid[i][j] = 1;
			else
				newGrid[i][j] = gridstatus[i][j];
		}
	}

	for (int i = 0; i < 48; i++)
		for (int j = 0; j < 33; j++)
			gridstatus[i][j] = newGrid[i][j];
}