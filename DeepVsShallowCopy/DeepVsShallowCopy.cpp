// DeepVsShallowCopy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Product {
private:

public:
	int product_id;
	int* product_quantity;
	Product()
	{
		product_quantity = new int;
	}
	void Set_Product(int id, int q);

	//Copy constructor
	Product(Product& p);
	
	//Assaignment Operator
	Product& operator=(Product& p);

	
	void detail();
	~Product()
	{
		delete product_quantity;
		product_quantity = NULL;
	}

};


int main()
{
#pragma region Shallow copy and its problem :
	Product p;
	p.Set_Product(1, 1000);
	p.detail();

	//Product p1 = p;//Shallow copy 
	//or Product p1(p);
	/*
	* int field copy from p to p1
	* but in pointer case value not share with p1 but address
	* if destructor will called thrugh p then p1's pointer has garbage
	* 
	* SOLUTION: create own copy constructor in which p obj will pass as
	  parameter and assign its values to p1 obj after assaining memory
	  ANOTHER problem when we assaign obj=obj1
	  SOLUTION : overload assaignment operator
	*/

	//p1.detail();
	//p1.Set_Product(2, 2000);
	//p.detail();
	//p1.detail();

	Product p2;
	p2 = p;//assaignment operator
	p2.detail();
	p2.Set_Product(2, 2000);
	p.detail();
	p2.detail();
#pragma endregion

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

void Product::Set_Product(int id, int q)
{
	product_id = id;
	*product_quantity = q;
}

#pragma region Copy Constructor that copy Pointer val after assaign it memory block
//Produtc p1=p;
                        //p
Product::Product(Product& p)
{
	product_quantity = new int;
	//p1's properties=p.properties
	*product_quantity = *(p.product_quantity);

	product_id = p.product_id;

}
Product& Product::operator=(Product& p)
{
	// TODO: insert return statement here
	if (this != &p) {
		product_quantity = new int;
		//p1's properties=p.properties
		*product_quantity = *(p.product_quantity);

		product_id = p.product_id;
	}
	return *this;
}
#pragma endregion



void Product::detail()
{
	cout << "Product Id : "  << product_id << endl;
	cout << "Product Quantity : " <<*( product_quantity) << endl;

}
