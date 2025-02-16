//============================================================================
// Autor: Diardon
// Blog : https://diardon.wordpress.com/
//============================================================================

#include <iostream>
#include <type_traits>
#include <typeinfo>

using namespace std;

template<typename T>
void checkType1(T value)
{
	// Disponible desde C++11
	if constexpr(std::is_floating_point<T>::value)
	{
		std::cout << "El tipo es de punto flotante" << endl;
	}
	else
	{
		std::cout << "El tipo no es de punto flotante" << endl;
	}
}

template<typename T>
void checkType2(T value)
{
	// Disponible desde C++17
	if constexpr (std::is_floating_point_v<T>)
	{
		std::cout << "El tipo es de punto flotante" << endl;
	}
	else
	{
		std::cout << "El tipo no es de punto flotante" << endl;
	}
}

class Base
{
	private:
		int value;
		int arr[5];
	public:
		Base():value(0), arr{1, 2, 3, 4, 5}{};
		virtual ~Base() = default;
};

class Derivada : public Base
{
	private:
		float num;
	public:
		Derivada():num(0){};
		virtual ~Derivada() = default;
};

void test1();
void test2();
void test3();

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}
void test3()
{
	Derivada d;
	Base *b = &d;

	// Usamos typeid para obtener información del tipo
	std::cout << "Tipo real: " << typeid(*b).name() << std::endl;
	std::cout << "Tipo de puntero: " << typeid(b).name() << std::endl;
}
void test2()
{
    std::cout << "Tamaño de int: " << sizeof(int) << " bytes" << std::endl;
    int arr[10];
    std::cout << "Tamaño del arreglo arr: " << sizeof(arr) << " bytes" << std::endl;
    Base b;
    std::cout << "Tamaño de objeto: " << sizeof(b) << " bytes" << std::endl;
}
void test1()
{
	checkType1(2.77);
	checkType1(17);

	checkType2(2.77);
	checkType2(17);
}
