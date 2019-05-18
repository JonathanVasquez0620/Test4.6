//park cars in driveway and then retrieve and car

#include <iostream>
#include <stack>

using namespace std;

void parkCar(stack<int>& d, int car);
void getCar(stack<int>& d, int car);
void print(stack<int> s);

int main()
{
	int car = 0;
	stack<int> driveway;
	stack<int> street;
	bool end = false;
	int choice = 0;
	while (!end)
	{
		cout << endl << "Enter 1 to park a car in the drive way or 2 to retieve a car: ";
		cin >> choice;

		if (choice == 1)
		{
			cout << endl << "Enter the number of the car to park in the driveway:";
			cin >> car;
			parkCar(driveway, car);
			print(driveway);
			end = false;
		}
		else if (choice == 2)
		{
			cout << endl << "Enter the number of the car to retrieve from the driveway:";
			cin >> car;
			getCar(driveway, car);
			end = false;
		}
		else
		{
			end = true;
		}
		
	} 

	cout << "Have a nice day.  Drive safe." << endl;


	return 0;
}

void parkCar(stack<int>& s, int car)
{
	stack<int> temp = s;
	temp.push(car);
	s = temp;
	return;
}

void getCar(stack<int>& d, int car)
{
	stack<int> temp = d;
	stack<int> street;
	int mid = -1;
	while (mid != car)
	{
		mid = temp.top();
		temp.pop();
		street.push(mid);
		print(temp);
		cout << "Driveway" << endl;
		print(street);
		cout << endl;
	}
	street.pop();
	while (street.size() > 0)
	{
		mid = street.top();
		street.pop();
		temp.push(mid);
		cout << "Driveway" << endl;
		print(temp);
		cout << endl << "Street" << endl;
		print(street);
		cout << endl;
	}
	d = temp;
	return;
}

void print(stack<int> s)
{
	stack<int> temp = s;
	while (temp.size() > 0)
	{
		cout  << temp.top() << " ";
		temp.pop();
	}
}
