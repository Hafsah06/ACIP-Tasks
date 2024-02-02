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
	double weightsStart[classSize];
	double weightsEnd[classSize];
	double weightDifference[classSize];
	string names[classSize];

	cout << "Enter the names and weights for a class of 30 pupils (First Day of Term)." << endl;
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
			cin >> weightsStart[i];

			if (!isweightvalid(weightsStart[i]))
			{
				cout << "Invalid weight! Please enter a weight between 2o to 150 KGs." << endl;
			}
		} while (!isweightvalid(weightsStart[i]));

	}
	cout << endl;

	cout << "Enter the weights for the same class of 30 pupils (Last Day of Term) ." << endl;
	for (int i = 0; i < classSize; ++i)
	{
		do
		{
			cout << "Enter weight for pupil " << i + 1 << " on the last (in kilograms) : ";
			cin >> weightsEnd[i];

			if (!isweightvalid(weightsEnd[i]))
			{
				cout << "Invalid weight! Please enter a weight between 20 to 150 Kgs." << endl;
			}
		} while (!isweightvalid(weightsEnd[i]));

		weightDifference[i] = weightsEnd[i] - weightsStart[i];
	}

	cout << "Names, Weights on the First Day, Weights on the Last Day, and Weight Difference: " << endl;
	for (int i = 0; i < classSize; ++i)
	{
		cout << "Name: " << names[i] << " , Initial Weight: " << weightsStart[i] << " kg, Final Weight:" << weightsEnd[i] << " kg, Weight Difference: " << weightDifference[i] << " kg" << endl;
	}

	return 0;
}