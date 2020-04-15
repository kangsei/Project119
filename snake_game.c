#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#define y_length 6
#define x_length 16
#define Map_x 47
#define Map_y 25
#define Snake_x 47
#define Snake_y 25

int map[Map_y][Map_x];
int key;	//Ű���� �Է��� ���� �� ����ϴ� ����
int cnt = 3;	//�� ���� ����
int global_life = 4;	//������ 0 ���� �� ���α׷��� ������ ���� ����
int score = 0;	//����

typedef struct _location
{
	int x;
	int y;
}location;
location food;	//������ ��µ� ��ġ�� ����Ǵ� ����
location snake_head;	//���� �Ӹ� ��ġ�� ����
location snake_tail;	//���� ������ ��ġ�� ����
location body[25];	//���� �� ���� �κ��� ��ġ�� �����ϴ� ����
location temp[25];	//body[][]������ ������Ʈ �� �� ����ϴ� �ӽ� ���� ����

typedef struct _direction
{
	int up;
	int down;
	int left;
	int right;
}direction;
direction snake_d[Snake_y][Snake_x];	//���� �� ������ �̵��� ��ġ�� �����ϴ� ����
direction d;	//���� �̵� ��ġ�� �����ϴ� ����

void Game_instructions();
void Console();

void Map_init();	//�� �ʱ�ȭ �ϴ� �Լ�
void Map();		//�� ����ϴ� �Լ�
void Score();	//���� ����ϴ� �Լ�
void Life();	//���� ����ϴ� �Լ�
void Food();	//���� ����ϴ� �Լ�
void Foodeat();	//������ ������ ������ �ö󰡰� ������ �ٽ� ������
void Die();	//���̳� �ڱ� �ڽ����� ����� �� ���� ���̰� �ٽ� ����� ���ư��� �Լ�

void Up();	//���� �̵� ��ġ�� up���� ����
void Down();	//���� �̵� ��ġ�� down���� ����
void Left();	//���� �̵� ��ġ�� left�� ����
void Right();	//���� �̵� ��ġ�� right�� ����

void Snake_init();	//�� �ʱ�ȭ �ϴ� �Լ�
void Temp_init();	//�� ���� �� �κ��� ��ġ�� �����ϴ� ���� ������Ʈ
void Create(); //�� �Ӹ� �����ϴ� �Լ�
void Delete();	//�� ���� �����ϴ� �Լ�
void Snake_plus();	//���� ���� �� ���� �þ�� �ϴ� �Լ�
void Move();	//�� �����̰� �ϴ� �Լ�

void gotoxy(int x, int y);	//���ϴ� ��ġ�� ���
void Event();	//�̽��Ϳ���, ���� ����, ���� �Ӹ��� ������ ������ ����
int main();	//���� �Լ�

void Game_instructions()
{
	system("color 07");
	printf("\n\n\n\n");
	printf("\t\t\t\tGame instruction\n");
	printf("\n\n\n");
	printf("-> ����Ű�� ������ ���� �����Ӵϴ�.\n\n");
	printf("-> ���� ������ �� �ִ� â �ȿ��� ������ �������� ������ ���Դϴ�. ���� ������ ���� ������ ���� ���̰� ��ĭ �þ��, ������ 10�� �����ϴ�.\n\n");
	printf("-> ������ �� 3�� �Դϴ�. ���� ���� ��ų� ���� ���뿡 ������ ������ �ϳ��� �پ��ϴ�.\n\n");
	printf("-> �ƹ�Ű�� ������ ������ ���߿� �Ͻ����� �� �� �ֽ��ϴ�. �ٽ� ������ �����Ϸ��� ����Ű�� ������ �˴ϴ�.\n\n");
	printf("-> ���� ����� ������ ���߿� ������ �ʹٸ� esc�� ��������\n\n");
	printf("Press the key to play game...");
	if (_getch()) {
	}
}

void Console()
{
	system("cls");
	system("color 72");
}

void Map_init()	//map[][]�ʱ�ȭ �ϴ� �Լ�
{
	int i;
	int j;
	for (i = 0; i < Map_y; i++) {
		for (j = 0; j < Map_x; j++) {
			if (i == 0 || i == 24 || j == 0 || j == 46) {
				map[i][j] = 1;
			}
			else {
				map[i][j] = 0;
			}
		}
	}
}

void Map()	//�� ����ϴ� �Լ�
{
	int i;
	int j;
	for (i = 0; i < Map_y; i++) {
		for (j = 0; j < Map_x; j++) {
			if (map[i][j] == 1) {
				gotoxy(x_length - 2 + (j * 2), y_length - 1 + i);
				printf("��");
			}
			else {
				gotoxy(x_length - 2 + (j * 2), y_length - 1 + i);
				printf("  ");
			}
		}
		printf("\n");
	}

	gotoxy(x_length + 24, 3);
	printf("Score: %d", score);
}

void Score()	//������ ���ʿ� ���
{
	score += 10;
	gotoxy(x_length + 24, 3);
	cnt += 1;
	printf("Score: %d", score);
}

void Life()		//������ ���ʿ� ���
{
	static int life = 4;
	life -= 1;
	global_life -= 1;
	gotoxy(x_length + 60, 3);
	printf("Life: %d", life);
}

void Food()
{
	srand(time(NULL));
	food.x = rand() % 45;
	food.y = rand() % 23;
	gotoxy(x_length + (food.x * 2), y_length + food.y);
	printf("��");
}

void Foodeat()
{
	if (food.x == snake_head.x && food.y == snake_head.y) {
		Score();
		Food();
	}
}

void Die()
{
	int i;
	int temp = 1;
	if (snake_head.x == 46 || snake_head.x < 0 || snake_head.y < 0 || snake_head.y == 23) {
		main();
	}
	for (i = 1; i < cnt - 1; i++) {
		if (snake_head.x == body[i].x && snake_head.y == body[i].y) {
			main();
		}
	}
	if (snake_head.x == body[cnt - 1].x && snake_head.y == body[cnt - 1].y) {
		Event();
	}
}

void Up()
{
	d.up = 1;
	d.down = 0;
	d.left = 0;
	d.right = 0;
}

void Down()
{
	d.up = 0;
	d.down = 1;
	d.left = 0;
	d.right = 0;
}

void Left()
{
	d.up = 0;
	d.down = 0;
	d.left = 1;
	d.right = 0;
}

void Right()
{
	d.up = 0;
	d.down = 0;
	d.left = 0;
	d.right = 1;
}

void Snake_init()
{
	int i;
	int j;
	int k;
	for (i = 0; i < Snake_y; i++) {
		for (j = 0; j < Snake_x; j++) {
			body[i].x = 0;
			body[i].y = 0;
			temp[i].x = 0;
			temp[i].y = 0;
			snake_d[i][j].up = 0;
			snake_d[i][j].down = 0;
			snake_d[i][j].left = 0;
			snake_d[i][j].right = 0;
		}
	}

	snake_head.x = 23;
	snake_head.y = 11;
	snake_tail.x = 24 - cnt;
	snake_tail.y = 11;

	for (k = 0; k < cnt; k++) {
		gotoxy(x_length + (snake_head.x - k) * 2, y_length + snake_head.y);
		printf("��");
		body[k].x = snake_head.x - k;
		body[k].y = 11;
		if (k == cnt - 1) {
			break;
		}
		snake_d[11][22 - k].right = 1;
	}
}

void Temp_init()
{
	int i;
	for (i = 0; i < cnt; i++) {
		temp[i] = body[i];
	}
}

void Create()	//�� ������ �� �Ӹ� �����ϴ� �Լ�
{
	int i;
	if (d.up == 1) {
		snake_d[snake_head.y][snake_head.x].up = 1;
		snake_head.y -= 1;
		gotoxy(x_length + (snake_head.x) * 2, y_length + snake_head.y);
		printf("��");
	}
	else if (d.down == 1) {
		snake_d[snake_head.y][snake_head.x].down = 1;
		snake_head.y += 1;
		gotoxy(x_length + (snake_head.x) * 2, y_length + snake_head.y);
		printf("��");
	}
	else if (d.left == 1) {
		snake_d[snake_head.y][snake_head.x].left = 1;
		snake_head.x -= 1;
		gotoxy(x_length + (snake_head.x) * 2, y_length + snake_head.y);
		printf("��");
	}
	else if (d.right == 1) {
		snake_d[snake_head.y][snake_head.x].right = 1;
		snake_head.x += 1;
		gotoxy(x_length + (snake_head.x) * 2, y_length + snake_head.y);
		printf("��");
	}
	Temp_init();
	for (i = 0; i < cnt; i++) {
		if (i == cnt - 1) {
			break;
		}
		body[i + 1] = temp[i];
	}
	body[0].x = snake_head.x;
	body[0].y = snake_head.y;
}

void Delete()	//�ǵڿ� �ִ� �� ���� �����ϴ� �Լ�
{
	if (snake_d[snake_tail.y][snake_tail.x].up == 1) {
		snake_d[snake_tail.y][snake_tail.x].up = 0;
		gotoxy(x_length + (snake_tail.x) * 2, y_length + snake_tail.y);
		printf("  ");
		snake_tail.y -= 1;
	}
	else if (snake_d[snake_tail.y][snake_tail.x].down == 1) {
		snake_d[snake_tail.y][snake_tail.x].down = 0;
		gotoxy(x_length + (snake_tail.x) * 2, y_length + snake_tail.y);
		printf("  ");
		snake_tail.y += 1;
	}
	else if (snake_d[snake_tail.y][snake_tail.x].left == 1) {
		snake_d[snake_tail.y][snake_tail.x].left = 0;
		gotoxy(x_length + (snake_tail.x) * 2, y_length + snake_tail.y);
		printf("  ");
		snake_tail.x -= 1;
	}
	else if (snake_d[snake_tail.y][snake_tail.x].right == 1) {
		snake_d[snake_tail.y][snake_tail.x].right = 0;
		gotoxy(x_length + (snake_tail.x) * 2, y_length + snake_tail.y);
		printf("  ");
		snake_tail.x += 1;
	}
}

void Snake_plus()
{
	if (food.x == snake_head.x && food.y == snake_head.y) {
		Foodeat();
		Create();
	}
}

void Move()
{
	while (1) {
		Create();
		Snake_plus();
		Delete();
		Sleep(100);
		Die();
		if (_kbhit()) {
			break;
		}
	}
}

void gotoxy(int x, int y)	//���ϴ� ��ġ�� ���
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Event()
{
	int i;
	int j;
	Console();
	gotoxy(x_length + 24, 3);
	printf("Score: %d", score);
	gotoxy(x_length + 60, 3);
	printf("Life:   ");
	for (i = 0; i < Map_y; i++) {
		for (j = 0; j < Map_x; j++) {
			gotoxy(x_length - 2 + (j * 2), y_length - 1 + i);
			printf("��");
			Sleep(1);
		}
	}
	gotoxy(x_length - 2 + 37, y_length - 1 + 13);
	printf(" HIDDEN ENDING ");
	gotoxy(x_length - 2 + 37, y_length - 1 + 14);
	printf("Press the key...");
	if (_getch()) {}
	exit(0);
}

int main()
{
	if (global_life == 4) {
		Game_instructions();
	}
	Console();
	Map_init();
	Map();
	Snake_init();
	Life();
	Food();
	while (1) {
		if (_kbhit()) {
			key = _getch();
			if (key == 72) {
				Up();
				Move();
				key = 0;
			}
			else if (key == 80) {
				Down();
				Move();
				key = 0;
			}
			else if (key == 75) {
				Left();
				Move();
				key = 0;
			}
			else if (key == 77) {
				Right();
				Move();
				key = 0;
			}
			else if (key == 27) {
				Console();
				gotoxy(x_length + 35, y_length + 9);
				printf("GAME OVER");
				gotoxy(x_length + 35, y_length + 10);
				printf("Press the key...");
				if (_getch()) {
				}
				exit(0);
			}
			else {
				if (_getch) {
				}
			}
		}
		if (global_life == 0) {
			Console();
			Map();
			gotoxy(x_length + 35, y_length + 9);
			printf("GAME OVER");
			gotoxy(x_length + 35, y_length + 10);
			printf("Your Score: %d", (cnt - 3) * 10);
			gotoxy(x_length + 35, y_length + 11);
			printf("Press the key...");
			if (_getch()) {
			}
			exit(0);
		}
	}
}
