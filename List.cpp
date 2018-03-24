/*************************************************************
�������� ������ �� ���������� "���������������� (�����������)"
�������� ������ ���.��.1.1
����� �.�.
������� �23:
����������� �������� ���������� ����������� ������ ��� �������� �����������. ���������� ��������� ����������������:
�) �������� ���������� � ������;
�) ���������� �������� ������ �� N ��������� ������;
�) ���������� �������� ������ �� N ��������� �����;
�) ��������� ������ � �����
�) ������� ������ �� �����
*************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "List_Header.h"

int menu_selection;		// ���������� ��� ������ �������
int counter = 0;		// ������� ����� ������

int main()
{
	List *u = NULL;			// ���������� ��������� �� ������ �������� ������
	List *x = u;			// ��������������� ����������-���������, ������� ����� ������� ����� ���������� ���� ������
							// ������ ��������� ���� ������ ��������� � ��� �������
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