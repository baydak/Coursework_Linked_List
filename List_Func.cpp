#include <iostream>
#include <iomanip>
#include <fstream>
#include "List_Header.h"

// ���� ������ ��������
int Menu()
{
	std::cout << "1 :  Add an element to the top" << std::endl;
	std::cout << "2 :  Add an element to the end" << std::endl;
	std::cout << "3 :  Show List" << std::endl;
	std::cout << "4 :  Remove an element at the beginning of the list" << std::endl;
	std::cout << "5 :  Remove an element at the end of the list" << std::endl;
	std::cout << "6 :  Delete an item with serial number N" << std::endl;
	std::cout << "7 :  Remove the list" << std::endl;
	std::cout << "8 :  Sort ascending radius" << std::endl;
	std::cout << "9 :  Move the list to the right" << std::endl;
	std::cout << "10 : Move the list to the left" << std::endl;
	std::cout << "11 : Save list to a file" << std::endl;
	std::cout << "12 : Save an element of radius R in a file" << std::endl;
	std::cout << "13 : Show list from file" << std::endl;
	std::cout << "0 :  EXIT" << std::endl;
	std::cout << "Select an action: ";
	std::cin >> menu_selection;
	std::cout << std::endl;
	return menu_selection;
}

// 1 - ���������� ������ ���� � ������ ������
void Add_top(List **u, List **x)
{
	double temp_x, temp_y, temp_rad;
	std::cout << std::setw(15) << "Enter values:" << std::endl;
	std::cout << std::setw(15) << "x = ";
	std::cin >> temp_x;
	std::cout << std::setw(15) << "y = ";
	std::cin >> temp_y;
	std::cout << std::setw(15) << "radius = ";
	std::cin >> temp_rad;
	std::cout << std::endl;
	if (*u == NULL)						// �����������, ���� � ������ ��� ��� �����
	{
		*u = new List;					// �������� ������ ��� ���� ������
		(*u)->d.coord_x = temp_x;		// ��������� ���� � �������
		(*u)->d.coord_y = temp_y;
		(*u)->d.rad = temp_rad;
		(*u)->next = NULL;				// ��������� �� ��������� ���� ������ ����
		(*x) = (*u);					
	}
	else
	{
		List *t = new List;
		t->d.coord_x = temp_x;
		t->d.coord_y = temp_y;
		t->d.rad = temp_rad;
		t->next = *u;
		*u = t;
	}	
	counter++;							// ��������� �������� ����� ������
}

// 2 - ���������� ������ ���� � ����� ������
void Add_end(List **u, List **x)
{
	double temp_x, temp_y, temp_rad;
	std::cout << std::setw(15) << "Enter values:" << std::endl;
	std::cout << std::setw(15) << "x = ";
	std::cin >> temp_x;
	std::cout << std::setw(15) << "y = ";
	std::cin >> temp_y;
	std::cout << std::setw(15) << "radius = ";
	std::cin >> temp_rad;
	std::cout << std::endl;
	if (*u == NULL)
	{
		*u = new List;			
		(*u)->d.coord_x = temp_x;		
		(*u)->d.coord_y = temp_y;
		(*u)->d.rad = temp_rad;
		(*u)->next = NULL;			
		(*x) = (*u);
	}
	else
	{
		(*x)->next = new List;
		(*x) = (*x)->next;
		(*x)->d.coord_x = temp_x;
		(*x)->d.coord_y = temp_y;
		(*x)->d.rad = temp_rad;
		(*x)->next = NULL;
	}
	counter++;
}

// 3 - �������� ������
void Print(List *u)
{
	if (u)
	{
		List *p = u;
		std::cout << std::setw(15) << "List:" << std::endl;
		while (p)
		{
			std::cout << std::setw(15) << "x = " << p->d.coord_x << "\ty = " << p->d.coord_y << "\tradius = " << p->d.rad << std::endl;
			p = p->next;
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "\t nothing to print - the list is empty" << std::endl;
		std::cout << std::endl;
	}
}

// 4 - �������� ������� ���� ������
void Delete_top(List **u, List **x)
{
	if (*u == NULL)											// �����������, ���� � ������ ��� �����
	{
		std::cout << "\t the list is empty - nothing to remove" << std::endl;
		std::cout << std::endl;
	}
	else if (*u == *x)										// �����������, ���� � ������ ����� ���� ����
	{
		delete (*u);
		*u = NULL;
		*x = NULL;
		counter = 0;
		std::cout << "\t list was deleted" << std::endl;
		std::cout << std::endl;
	}
	else													// �����������, ���� � ������ ��� � ����� �����
	{
		List *t = *u;
		*u = t->next;
		delete t;
		std::cout << "\t the first element of the list is removed" << std::endl;
		std::cout << std::endl;
		counter--;											// ��������� �������� ����� ������
	}
}

// 5 - �������� ���������� ���� ������
void Delete_end(List **u, List **x)
{
	if (*u == NULL)
	{
		std::cout << "\t the list is empty - nothing to remove" << std::endl;
		std::cout << std::endl;
	}
	else if (*u == *x)
	{
		delete (*u);
		*u = NULL;
		*x = NULL;
		counter = 0;
		std::cout << "\t list was deleted" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		List *p = (*u);
		List *t = (*u);
		while (p != (*x))
		{
			t = p;
			p = p->next;
		}
		delete p;
		t->next = NULL;
		(*x) = t;
		counter--;
		std::cout << "\t the last item removed" << std::endl;
		std::cout << std::endl;
	}
}

// 6 - �������� n-�� ���� ������
void Delete_index(List **u, List **x)
{
	if (*u == NULL)						// ���� ������ ����
	{
		std::cout << "\t the list is empty - nothing to remove" << std::endl;
		std::cout << std::endl;
		return;
	}

	int index;
	printf("\t Enter the serial number of the element to remove (from 1 to %i): ", counter);
	std::cin >> index;



	if ((index < counter) && (index != 1))				// ���� n-�� ���� ���������� � �� ������
	{
		List *left = (*u);
		List *del = left->next;
		List *right = del->next;
		int local_counter = 2;			// ������ ��� � ������ left|del|right ��������� ���� ���������� ������ �� �����

		while (local_counter != index)
		{
			left = left->next;
			del = del->next;
			right = right->next;
			local_counter++;
		}
		delete del;
		left->next = right;
		printf("\t Item number %i has been removed", index);
		std::cout << std::endl;
		std::cout << std::endl;
		counter--;
	}

	else if (counter < index)			// ���� n-�� ���� �� ���������� 
	{
		printf("\t The element %i does not exist. The list contains %i elements", index, counter);
		std::cout << std::endl;
		std::cout << std::endl;
	}

	else if (index == 1)				// ���� ���������� ������� ������ ����
	{
		List *t = *u;
		*u = t->next;
		delete t;
		printf("\t Item number %i has been removed", index);
		std::cout << std::endl;
		std::cout << std::endl;
		counter--;
	}

	else if (index == counter)			// ���� ���������� ������� ��������� ����
	{
		List *p = (*u);
		List *t = (*u);
		while (p != (*x))
		{
			t = p;
			p = p->next;
		}
		delete p;
		t->next = NULL;
		(*x) = t;
		printf("\t Item number %i has been removed", index);
		std::cout << std::endl;
		std::cout << std::endl;
		counter--;
	}
}

// 7 - �������� (�������) ����� ������
void Clear(List **u, List **x)
{
	if (*u == NULL)
	{
		std::cout << "\t the list is empty - nothing to remove" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		List *p = *u;
		List *t;
		while (p)
		{
			t = p;
			p = p->next;
			delete t;
		}
		*u = NULL;
		*x = NULL;
		counter = 0;
		std::cout << "\t list was deleted" << std::endl;
		std::cout << std::endl;
	}
}

// 8 - ���������� ����� ������ �� ����������� �������
void Sort_rad_asc(List **u, List **x)
{
	if (*u != NULL)
	{
		List *left;
		List *right;
		List *tmp;
		List *p = (*u);
		List *end = (*x);
		while (p != end)		
		{
			left = p;
			right = left->next;

			do
			{
				if (right->d.rad < left->d.rad)			// ���� ��������� � ������
				{
					double tmp_rad = right->d.rad;
					right->d.rad = left->d.rad;
					left->d.rad = tmp_rad;

					double tmp_x = right->d.coord_x;
					right->d.coord_x = left->d.coord_x;
					left->d.coord_x = tmp_x;

					double tmp_y = right->d.coord_y;
					right->d.coord_y = left->d.coord_y;
					left->d.coord_y = tmp_y;
				}

				tmp = left;
				left = left->next;
				right = right->next;

			} while (right != end->next);		
			end = tmp;
		}
		std::cout << "\t the list has been sorted" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "\t the list is empty - nothing to sort" << std::endl;
		std::cout << std::endl;
	}
}

// 9 - ����� ������ �� N ����� ������
void Move_right(List **u, List **x)
{
	if ((*u) == NULL)						// ���� ������ ����
	{
		std::cout << "\t the list is empty - there is nothing to move" << std::endl;
		std::cout << std::endl;
	}
	else if (*u == *x)						// ���� � ������ ����� ���� ����
	{
		std::cout << "\t list consists of a single element - move does not make sense" << std::endl;
		std::cout << std::endl;
	}
	else									// ���� � ������ ��� � ����� �����
	{
		int shift;
		int local_counter = 0;
		(*x)->next = (*u);				// �������� ������� ������
		std::cout << "\t the value to which to move to the right = ";
		std::cin >> shift;
		std::cout << std::endl;

		do
		{
			(*u) = (*u)->next;
			(*x) = (*x)->next;
			local_counter++;
		} while (local_counter != shift);

		(*x)->next = NULL;				// ����������� ��������� ������ ����� � �����������
		std::cout << "\t list has been moved" << std::endl;
		std::cout << std::endl;
	}
}

// 10 - ����� ������ �� N ����� �����
void Move_left(List **u, List **x)
{
	if ((*u) == NULL)						// ���� ������ ����
	{
		std::cout << "\t the list is empty - there is nothing to move" << std::endl;
		std::cout << std::endl;
	}
	else if (*u == *x)						// ���� � ������ ����� ���� ����
	{
		std::cout << "\t list consists of a single element - move does not make sense" << std::endl;
		std::cout << std::endl;
	}
	else									// ���� � ������ ��� � ����� �����
	{

		int shift;
		int local_counter = 0;
		(*x)->next = (*u);				// �������� ������� ������
		std::cout << "\t the value to which to move to the left = ";
		std::cin >> shift;
		std::cout << std::endl;

		if (counter > shift)
		{
			do
			{
				(*u) = (*u)->next;
				(*x) = (*x)->next;
				local_counter++;
			} while (local_counter != (counter - shift));
		}
		else if (counter < shift)
		{
			do
			{
				shift = shift % counter;
				(*u) = (*u)->next;
				(*x) = (*x)->next;
				local_counter++;
			} while (local_counter != (counter - shift));
		}

		(*x)->next = NULL;				// ����������� ��������� ������ ����� � �����������
		std::cout << "\t list has been moved" << std::endl;
		std::cout << std::endl;
	}
}

// 11 - ���������� � ����
void File_in(List *u)
{
	if (u)
	{
		List *p = u;
		std::ofstream fout("linked_list.txt");
		fout << std::setw(15) << "List:" << std::endl;
		while (p)
		{
			fout << std::setw(15) << "x = " << p->d.coord_x << "\ty = " << p->d.coord_y << "\tradius = " << p->d.rad << std::endl;
			p = p->next;
		}
		fout.close();
		std::cout << "\t the list has been saved to a file \"linked_list.txt\" " << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "\t list is empty - nothing to save in a file" << std::endl;
		std::cout << std::endl;
	}
}

// 12 - ���������� ����� � �������� �������� � ����
void File_in_rad(List *u)
{
	if (u)
	{
		int radius_search;
		int local_count = 1;
		int search_quantity = 0;
		std::cout << std::setw(15) << "\t Enter the radius for the search in the list: ";
		std::cin >> radius_search;

		List *p = u;
		std::ofstream fout("linked_list_rad.txt");
		fout << std::setw(15) << "List of elements with a radius " << radius_search << std::endl;
		while (p)
		{
			if (p->d.rad == radius_search)
			{
				fout << std::setw(15) << local_count << "\tx = " << p->d.coord_x << "\ty = " << p->d.coord_y << "\tradius = " << p->d.rad << std::endl;
				search_quantity++;
			}
			p = p->next;
			local_count++;
		}
		fout.close();
		printf("\t List of elements with a radius %i has been saved in a file linked_list_rad.txt", radius_search);
		//std::cout << "\t the list has been saved to a file \"linked_list_rad.txt\" " << std::endl;
		std::cout << std::endl;
		printf("\t %i elements found", search_quantity);
		std::cout << std::endl;
	}
	else
	{
		std::cout << "\t list is empty - nothing to save in a file" << std::endl;
		std::cout << std::endl;
	}
}

// 13 - ����������� �� �����
void File_out(List *u)
{
	if (u)
	{
		setlocale(LC_ALL, "rus");					// ���������� ����������� ���������
		char buff[50];								// ����� �������������� �������� ������������ �� ����� ������
		std::ifstream fin("linked_list.txt");
		while (!fin.eof())							// eof() ���������� 1, ���� ��� ��������� ����� �����; 
		{											// � ��������� ������ ��� ���������� 0
			fin.getline(buff, 50);
			std::cout << buff << std::endl;
		}

		fin.close();
	}
	else
	{
		std::cout << "\t list is empty - nothing to print" << std::endl;
		std::cout << std::endl;
	}
}