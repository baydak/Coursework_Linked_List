/*************************************************************
Курсовая работа по дисциплине "Программирование (процедурное)"
студента группы ПРГ.ИС.1.1
Байды К.И.
Задание №23:
Посредством структур реализуйте односвязный список для хранения окружностей. Обеспечьте следующую функциональность:
А) добавить окружность в список;
Б) циклически сдвинуть список на N элементов вправо;
В) циклически сдвинуть список на N элементов влево;
Г) сохранить данные в файле
Д) считать данные из файла
*************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "List_Header.h"

int menu_selection;		// Переменная для выбора функции
int counter = 0;		// Счётчик узлов списка

int main()
{
	List *u = NULL;			// Определяем указатель на начало будущего списка
	List *x = u;			// Вспомогательная переменная-указатель, которая будет хранить адрес последнего узла списка
							// Сейчас последний узел списка совпадает с его началом
	do
	{
		Menu();
		switch (menu_selection)
		{
		case 1:
			Add_top(&u, &x);
			break;
		case 2:
			Add_end(&u, &x);
			break;
		case 3:
			Print(u);
			break;
		case 4:
			Delete_top(&u, &x);
			break;
		case 5:
			Delete_end(&u, &x);
			break;
		case 6:
			Delete_index(&u, &x);
			break;
		case 7:
			Clear(&u, &x);
			break;
		case 8:
			Sort_rad_asc(&u, &x);
			break;
		case 9:
			Move_right(&u, &x);
			break;
		case 10:
			Move_left(&u, &x);
			break;
		case 11:
			File_in(u);
			break;
		case 12:
			File_in_rad(u);
			break;
		case 13:
			File_out(u);
			break;
		default:
			break;
		}
	} while (menu_selection != 0);
	
	return 0;
}