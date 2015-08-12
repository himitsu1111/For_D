#include <vcl>
#include <vector>
#include <iostream>

namespace moo
{



	class vector
	{
			int * mas;
			int mas_size;
			int mas_elements;

		public:

			vector(); //конструктор по умолчанию
						 /* Аргумент я сюда засунул потому,
						 что конструктор я вызываю из пушбека.
						 И чтобы там все работало, надо аргумент
						 передавать.			 */
			void push_back(int);
			int sizeAccessor() { return mas_size;}
			int elementsAccessor() { return mas_elements;}
			int needToGrow() { return (mas_elements>=mas_size) ? 1 : 0; }
			~vector() { delete[] mas; }
			int& operator[](int ind_mas) { return mas[ind_mas]; }
	};

	vector::vector() : mas(0), mas_size(0), mas_elements(0) {} //конструктор по умолчанию
                       //список инициализации

	void vector::push_back(int elem)
	{

		if (needToGrow())
		{
//			int Z = mas_size*1.49999999999999 + 1;
//			double K = mas_size*1.49999999999999 + 1;
			mas_size = (mas_size + 1)*1.49999999999999;
			int * new_mas = new int[mas_size]; //выделяется память для массива,
												 //равная размеру массива+1
			for (int i = 0; i < mas_elements; i++)   //указатели на элементы старого массива
				new_mas[i]=mas[i];               //копируются в указатели нового
			delete[] mas;      //память, выделенная mas удаляется
			mas = new_mas;     //mas начинает указывать на новый промежуток памяти,
							   //на который раньше указывал new_mas
		}
		mas[mas_elements++] = elem; //элемент добавляется в массив, размер увеличивается для следующей итерации
		//инкремент постфиксный потому, что Объект создавался (конструктором) пустой и массив в нем был пустой, поэтому
		//все итерации добавления в массив идут от 0, а только потом увеличивается размер массива mas_size
	}
}


void show_vector( std::vector<int>&a)
{
		for (std::vector<int>::iterator it = a.begin() ; it!=a.end() ; ++it)
				std::cout << *it << '\n';
}

void show_my_vector(moo::vector & b)
{
	for (int i = 0; i < b.elementsAccessor(); i++)
		std::cout << "moi vectorok-massivok " << b[i] << '\n' ;
}




int main()
{
	using namespace moo;

	vector K;
	K.push_back(666);
	K.push_back(222);
	K.push_back(111);
	K.push_back(333);
	K.push_back(555);
	K.push_back(999);
	K.push_back(666);
	K.push_back(222);
	K.push_back(111);
	K.push_back(333);
	K.push_back(555);
	K.push_back(999);

	std::vector<int> V;

	V.push_back(123);
	V.push_back(6574);
	
	show_my_vector(K);
	show_vector(V);
	
	system("pause");
	return 0;
}
