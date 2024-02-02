#include<iostream>
#include<string>
using namespace std;

const int classSize = 30;

bool isweightvalid(double weight)
{
	if (weight >= 20.0 && weight <= 150.0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isuniquename(const string& name, const string names[], int count)
{
	for (int i = 0; i < count; ++i)
	{
		if (name == names[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	double weights[classSize];
	string names[classSize];

	cout << "Enter the names and weights for a class of 30 pupils." << endl;
	for (int i = 0; i < classSize; ++i)
	{
		do
		{
			cout << "Enter name for pupil " << i + 1 << " : ";
			cin >> names[i];

			if (!isuniquename(names[i], names, i))
			{
				cout << "Name is not unique! Please enter a some unique name." << endl;
			}
		} while (!isuniquename(names[i], names, i));

		do
		{
			cout << "Enter the weight for pupil " << i + 1 << " (in Kgs) : ";
			cin >> weights[i];

			if (!isweightvalid(weights[i]))
			{
				cout << "Invalid weight! Please enter a weight between 2o to 150 KGs." << endl;
			}
		} while (!isweightvalid(weights[i]));

	}

	cout << "Names and Weughts of pupils are: " << endl;
	for (int i = 0; i < classSize; ++i)
	{
		cout << "Name: " << names[i] << " , Weight: " << weights[i] << " kg" << endl;
	}

	return 0;
}