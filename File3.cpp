#include <vcl>
#include <vector>
#include <iostream>

namespace moo
{



	class Vector
	{
			int * mas;
			int mas_size;

		public:

			Vector(); //конструктор по умолчанию
						 /* Аргумент я сюда засунул потому,
						 что конструктор я вызываю из пушбека.
						 И чтобы там все работало, надо аргумент
						 передавать.			 */
			void Pushback(int);
			void IndexMutator(int);
			sizeAccessor() { return mas_size;};
			~Vector() { delete[] mas; };
			int& operator[](int ind_mas) { return mas[ind_mas]; };
	};

	Vector::Vector() : mas(0), mas_size(0) {} //конструктор по умолчанию
                       //список инициализации

	void Vector::Pushback(int elem)
	{
		int * new_mas = new int[mas_size+1]; //выделяется память для массива,
											 //равная размеру массива+1
		for (int i = 0; i < mas_size; i++)   //указатели на элементы старого массива
			new_mas[i]=mas[i];               //копируются в указатели нового

		delete[] mas;      //память, выделенная mas удаляется
		mas = new_mas;     //mas начинает указывать на новый промежуток памяти,
						   //на который раньше указывал new_mas
		mas[mas_size++] = elem; //элемент добавляется в массив, размер увеличивается для следующей итерации
		//инкремент постфиксный потому, что Объект создавался (конструктором) пустой и массив в нем был пустой, поэтому
		//все итерации добавления в массив идут от 0, а только потом увеличивается размер массива mas_size
	}
}


void show_vector( std::vector<int>&a)
{
		for (std::vector<int>::iterator it = a.begin() ; it!=a.end() ; ++it)
				std::cout << *it << '\n';
}

void show_my_vector(moo::Vector & b)
{
	int max_size = b.sizeAccessor();

	for (int i = 0; i < max_size; i++)
		std::cout << "moi vectorok-massivok " << b[i] << '\n' ;
}




int main()
{
	using namespace moo;

	Vector K;
	K.Pushback(666);
	K.Pushback(222);

	std::vector<int> V;

	V.push_back(123);
	V.push_back(6574);
	
	show_my_vector(K);
	show_vector(V);
	
	system("pause");
	return 0;
}
