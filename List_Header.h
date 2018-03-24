#pragma once

extern int menu_selection;
extern int counter;

struct Data					// Структура, содержащая характеристики данных
{
	double coord_x;
	double coord_y;
	double rad;
};

struct List					// Структура, содержащая поле типа Data и поле - адрес последующего элемента next
{
	Data d;
	List *next;
};

int Menu();
void Add_top(List **u, List **x);
void Add_end(List **u, List **x);
void Print(List *u);
void Delete_top(List **u, List **x);
void Delete_end(List **u, List **x);
void Delete_index(List **u, List **x);
void Clear(List **u, List **x);
void Sort_rad_asc(List **u, List **x);
void Move_right(List **u, List **x);
void Move_left(List **u, List **x);
void File_in(List *u);
void File_in_rad(List *u);
void File_out(List *u);
