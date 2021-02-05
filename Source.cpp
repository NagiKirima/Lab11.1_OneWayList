#include <iostream>
#include <vector>
using namespace std;
struct List
{
	int data;
	List* next_block;
};
int GetSize() 
{
	int size;
	cin >> size;
	while (size <= 0) 
	{
		cout << "Введите корректное число!\t";
		cin >> size;
	}
	return size;
}
List* CreateList(int size)
{
	List* first_element = nullptr;
	List* current_element;
	if (size == 1)
	{
		cout << "Введите 0-й элемент:\t";
		current_element = new List;
		cin >> (*current_element).data;
		first_element = current_element;
		current_element->next_block = nullptr;
	}
	else
	{
		cout << "Введите 0-й элемент:\t";
		current_element = new List;
		cin >> (*current_element).data;
		first_element = current_element;
		for (int i = 1; i < size; i++)
		{
			List* new_element = new List;
			(*current_element).next_block = new_element;
			current_element = new_element;
			cout << "Введите " << i << "-й элемент:\t";
			cin >> (*current_element).data;
			(*current_element).next_block = nullptr;
		}
	}
	return first_element;
}
void PrintList(List* current_element)
{
	if (current_element == nullptr) 
	{
		cout << "Список пуст!" << endl;
		return;
	}
	int i = 0;
	while (current_element != nullptr)
	{
		cout << i << "-й элемент списка\t" << (*current_element).data << endl;
		current_element = (*current_element).next_block;
		i++;
	}
}
int Size(List* current_element)
{
	int k = 0;
	while (current_element != nullptr)
	{
		current_element = (*current_element).next_block;
		k++;
	}
	return k;
}
bool DeleteElement(List*& first_element)
{
	vector <int> index;
	int size = Size(first_element);
	List* current_element = first_element;
	for (int i = 0; i < size; i++)
	{
		if (current_element->data % 2 == 0)
		{
			index.push_back(i);
		}
		current_element = current_element->next_block;
	}
	current_element = first_element;
	if (index.size() == 0)
	{
		cout << "Четных элементов нет!" << endl;
		return false;
	}
	if (index[index.size() - 1] == 0) 
	{
		first_element = first_element->next_block;
		delete current_element;
	}
	else
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (i == index[index.size() - 1] - 1) //предыдущий блок от того элемента, который мы хотим удалить 
			{
				List* tmp = current_element->next_block;
				current_element->next_block = current_element->next_block->next_block;
				delete tmp;
			}
			current_element = current_element->next_block;
		}
	}
	return true;
}
int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите размер списка:\t";
	int size = GetSize();
	cout << "=============================================" << endl;
	List* List_of_int_elements = CreateList(size);
	cout << "=============================================" << endl;
	cout << "Список перед удалением:" << endl;
	PrintList(List_of_int_elements);
	cout << "=============================================" << endl;
	bool check = DeleteElement(List_of_int_elements);
	if (!check) return 0;
	cout << "Список после удаления:" << endl;
	PrintList(List_of_int_elements);
	cout << "=============================================";
}