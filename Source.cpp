#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<chrono>
#include <thread>
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

char map[23][41] =
{  //1234567890123456789012345678901234678901
	"________________________________________",//1
	"|< ....................................|",//2
	"|.#########...............############.|",//3
	"|.#.........###..###.................#.|",//4
	"|.#.........#..EE..#.....#######.....#.|",//5
	"|.#..#......########.................#.|",//6
	"|.#..#...............................#.|",//7
	"|.......#.....############.....#..##...|",//8
	"|..###..#.....#          #.....#...#...|",//9
	"|.......#.....############.....#.......|",//10
	"|#####..#......................#..#####|",//11
	",......................................,",//12
	",...#######...############...#######...,",//13
	",......................................,",//14
	"|..#....#########......#########....#..|",//15
	"|..#................................#..|",//16
	"|..#.....#........###  ###......#...#..|",//17
	"|..#.....#........#..EE..#...####...#..|",//18
	"|..#.....#######..########...#......#..|",//19
	"|..#...........#....................#..|",//20
	"|..########....#.............########..|",//21
	"|......................................|",//22
	"|______________________________________|",//23
};


int x = 1, y = 1, pts = 0;
int Ex1 = 16;
int Ey1 = 4;
int Ex2 = 22;
int Ey2 = 17;
int Ex3 = 15;
int Ey3 = 4;
int Ex4 = 21;
int Ey4 = 17;
bool running = true;

int main()
{

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);



	while (running == true)
	{

		system("cls");

		for (int i = 0; i < 23; ++i)

		{
			cout << map[i] << endl;

		}
		/*SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);*/
		sleep_until(system_clock::now() + milliseconds(50));
		/*system("pause");*/
		if (GetAsyncKeyState(VK_DOWN))
		{
			SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
			if (map[y + 1][x] == ' ' || map[y + 1][x] == '.')
			{
				if (map[y + 1][x] == '.')
				{
					pts++;
				}
				map[y][x] = ' ';
				y++;

				map[y][x] = '^';
			}
			else if (map[y + 1][x] == 'E')
			{
				running = false;
			}
		}
		if (GetAsyncKeyState(VK_UP))
		{
			SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			if (map[y - 1][x] == ' ' || map[y - 1][x] == '.')
			{
				if (map[y - 1][x] == '.')
				{
					pts++;
				}
				map[y][x] = ' ';
				y--;
				map[y][x] = 'v';
			}
			else if (map[y - 1][x] == 'E')
			{
				running = false;
			}
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
			if (map[y][x - 1] == ',')
			{
				map[y][x] = ' ';
				x = x + 37;
				map[y][x] = '>';
			}
			if (map[y][x - 1] == ' ' || map[y][x - 1] == '.')
			{
				if (map[y][x - 1] == '.')
				{
					pts++;
				}
				map[y][x] = ' ';
				x--;
				map[y][x] = '>';
			}
			else if (map[y][x - 1] == 'E')
			{
				running = false;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);
			if (map[y][x + 1] == ',')
			{
				map[y][x] = ' ';
				x = x - 37;
				map[y][x] = '<';
			}

			if (map[y][x + 1] == ' ' || map[y][x + 1] == '.')
			{
				if (map[y][x + 1] == '.')
				{
					pts++;
				}
				map[y][x] = ' ';
				x++;
				map[y][x] = '<';
			}
			else if (map[y][x + 1] == 'E')
			{
				running = false;
			}
		}
		//enemy

		int random = rand() % 4 + 1;
		int randomm = rand() % 2 + 1;
		//enemy 1
		if (random == 1)
		{
			for (int i = 0; i < randomm; i++)
			{
				if (map[Ey1 + 1][Ex1] == ' ' || map[Ey1 + 1][Ex1] == '.')
				{
					if (map[Ey1 + 1][Ex1] == '.')
					{
						map[Ey1][Ex1] = '.';
					}
					else if (map[Ey1 + 1][Ex1] == ' ')
					{
						map[Ey1][Ex1] = ' ';
					}
					Ey1++;
					map[Ey1][Ex1] = 'E';
				}
			}
		}
		if (random == 2)
		{
			for (int i = 0; i < randomm; i++)
			{
				if (map[Ey1 - 1][Ex1] == ' ' || map[Ey1 - 1][Ex1] == '.')
				{
					if (map[Ey1 - 1][Ex1] == '.')
					{
						map[Ey1][Ex1] = '.';
					}
					else if (map[Ey1 - 1][Ex1] == ' ')
					{
						map[Ey1][Ex1] = ' ';
					}
					Ey1--;
					map[Ey1][Ex1] = 'E';
				}
			}
		}if (random == 3)
		{
			for (int i = 0; i < randomm; i++)
			{
				if (map[Ey1][Ex1 + 1] == ' ' || map[Ey1][Ex1 + 1] == '.')
				{
					if (map[Ey1][Ex1 + 1] == '.')
					{
						map[Ey1][Ex1] = '.';
					}
					else if (map[Ey1][Ex1 + 1] == ' ')
					{
						map[Ey1][Ex1] = ' ';
					}

					Ex1++;
					map[Ey1][Ex1] = 'E';
				}
			}
		}
		if (random == 4)
		{
			for (int i = 0; i < randomm; i++)
			{
				if (map[Ey1][Ex1 - 1] == ' ' || map[Ey1][Ex1 - 1] == '.')
				{
					if (map[Ey1][Ex1 - 1] == '.')
					{
						map[Ey1][Ex1] = '.';
					}
					else if (map[Ey1][Ex1 - 1] == ' ')
					{
						map[Ey1][Ex1] = ' ';
					}
					Ex1--;
					map[Ey1][Ex1] = 'E';
				}
			}
		}

		//enemy 2


		if (random == 2)
		{
			for (int i = 0; i < randomm; i++)
			{
				if (map[Ey2 + 1][Ex2] == ' ' || map[Ey2 + 1][Ex2] == '.')
				{
					if (map[Ey2 + 1][Ex2] == '.')
					{
						map[Ey2][Ex2] = '.';
					}
					else if (map[Ey2 + 1][Ex2] == ' ')
					{
						map[Ey2][Ex2] = ' ';
					}
					Ey2++;
					map[Ey2][Ex2] = 'E';
				}
			}
		}
		if (random == 3)
		{
			for (int i = 0; i < randomm; i++)
			{
				if (map[Ey2 - 1][Ex2] == ' ' || map[Ey2 - 1][Ex2] == '.')
				{
					if (map[Ey2 - 1][Ex2] == '.')
					{
						map[Ey2][Ex2] = '.';
					}
					else if (map[Ey2 - 1][Ex2] == ' ')
					{
						map[Ey2][Ex2] = ' ';
					}
					Ey2--;
					map[Ey2][Ex2] = 'E';
				}
			}
		}if (random == 4)
		{
			for (int i = 0; i < randomm; i++)
			{
				if (map[Ey2][Ex2 + 1] == ' ' || map[Ey2][Ex2 + 1] == '.')
				{
					if (map[Ey2][Ex2 + 1] == '.')
					{
						map[Ey2][Ex2] = '.';
					}
					else if (map[Ey2][Ex2 + 1] == ' ')
					{
						map[Ey2][Ex2] = ' ';
					}

					Ex2++;
					map[Ey2][Ex2] = 'E';
				}
			}
		}
		if (random == 1)
		{
			for (int i = 0; i < randomm; i++)
			{
				if (map[Ey2][Ex2 - 1] == ' ' || map[Ey2][Ex2 - 1] == '.')
				{
					if (map[Ey2][Ex2 - 1] == '.')
					{
						map[Ey2][Ex2] = '.';
					}
					else if (map[Ey2][Ex2 - 1] == ' ')
					{
						map[Ey2][Ex2] = ' ';
					}
					Ex2--;
					map[Ey2][Ex2] = 'E';
				}
			}
		}

		//enemy 3

		if (random == 3)
		{
			for (int i = 0; i < randomm; i++)
			{
				if (map[Ey3 + 1][Ex3] == ' ' || map[Ey3 + 1][Ex3] == '.')
				{
					if (map[Ey3 + 1][Ex3] == '.')
					{
						map[Ey3][Ex3] = '.';
					}
					else if (map[Ey3 + 1][Ex3] == ' ')
					{
						map[Ey3][Ex3] = ' ';
					}
					Ey3++;
					map[Ey3][Ex3] = 'E';
				}
			}
		}
		if (random == 4)
		{
			for (int i = 0; i < randomm; i++)
			{
				if (map[Ey3 - 1][Ex3] == ' ' || map[Ey3 - 1][Ex3] == '.')
				{
					if (map[Ey3 - 1][Ex3] == '.')
					{
						map[Ey3][Ex3] = '.';
					}
					else if (map[Ey3 - 1][Ex3] == ' ')
					{
						map[Ey3][Ex3] = ' ';
					}
					Ey3--;
					map[Ey3][Ex3] = 'E';
				}
			}
		}if (random == 1)
		{
			for (int i = 0; i < randomm; i++)
			{
				if (map[Ey3][Ex3 + 1] == ' ' || map[Ey3][Ex3 + 1] == '.')
				{
					if (map[Ey3][Ex3 + 1] == '.')
					{
						map[Ey3][Ex3] = '.';
					}
					else if (map[Ey3][Ex3 + 1] == ' ')
					{
						map[Ey3][Ex3] = ' ';
					}

					Ex3++;
					map[Ey3][Ex3] = 'E';
				}
			}
		}
		if (random == 2)
		{
			for (int i = 0; i < randomm; i++)
			{
				if (map[Ey3][Ex3 - 1] == ' ' || map[Ey3][Ex3 - 1] == '.')
				{
					if (map[Ey3][Ex3 - 1] == '.')
					{
						map[Ey3][Ex3] = '.';
					}
					else if (map[Ey3][Ex3 - 1] == ' ')
					{
						map[Ey3][Ex3] = ' ';
					}
					Ex3--;
					map[Ey3][Ex3] = 'E';
				}

			}
		}

		//enemy 4

		if (random == 4)
		{
			for (int i = 0; i < randomm; i++)
			{
				if (map[Ey4 + 1][Ex4] == ' ' || map[Ey4 + 1][Ex4] == '.')
				{
					if (map[Ey4 + 1][Ex4] == '.')
					{
						map[Ey4][Ex4] = '.';
					}
					else if (map[Ey4 + 1][Ex4] == ' ')
					{
						map[Ey4][Ex4] = ' ';
					}
					Ey4++;
					map[Ey4][Ex4] = 'E';
				}
			}
		}
		if (random == 1)
		{
			for (int i = 0; i < randomm; i++)
			{
				if (map[Ey4 - 1][Ex4] == ' ' || map[Ey4 - 1][Ex4] == '.')
				{
					if (map[Ey4 - 1][Ex4] == '.')
					{
						map[Ey4][Ex4] = '.';
					}
					else if (map[Ey4 - 1][Ex4] == ' ')
					{
						map[Ey4][Ex4] = ' ';
					}
					Ey4--;
					map[Ey4][Ex4] = 'E';
				}
			}
		}if (random == 2)
		{
			for (int i = 0; i < randomm; i++)
			{
				if (map[Ey4][Ex4 + 1] == ' ' || map[Ey4][Ex4 + 1] == '.')
				{
					if (map[Ey4][Ex4 + 1] == '.')
					{
						map[Ey4][Ex4] = '.';
					}
					else if (map[Ey4][Ex4 + 1] == ' ')
					{
						map[Ey4][Ex4] = ' ';
					}

					Ex4++;
					map[Ey4][Ex4] = 'E';
				}
			}
		}
		if (random == 3)
		{
			for (int i = 0; i < randomm; i++)
			{
				if (map[Ey4][Ex4 - 1] == ' ' || map[Ey4][Ex4 - 1] == '.')
				{
					if (map[Ey4][Ex4 - 1] == '.')
					{
						map[Ey4][Ex4] = '.';
					}
					else if (map[Ey4][Ex4 - 1] == ' ')
					{
						map[Ey4][Ex4] = ' ';
					}
					Ex4--;
					map[Ey4][Ex4] = 'E';
				}
			}
		}




		cout << "Score:" << pts;
		if (pts == 571)
		{


			running == false;
			break;
		}


	}
	system("cls");



	cout << endl << "----------GAME OVER-----------" << endl;
	cout << "Your score: " << pts << endl;
	cout << "Enter any key to exit: ";
	char e;
	cin >> e;

}

