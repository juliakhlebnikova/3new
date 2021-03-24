#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
using namespace std;


void print_v(std::vector<int> vec)
{
	cout << endl;
	for (vector<int>::iterator i = vec.begin(); i != vec.end(); i++)
	{
		cout << *i << ' ';
	}
	cout << endl << endl;
}

void print_m(vector<vector<int>> matr)
{
	cout << endl;
	for (vector<vector<int>>::iterator i = matr.begin(); i != matr.end(); i++)
	{
		for (vector<int>::iterator j = i->begin(); j != i->end(); j++)
		{
			cout << *j << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void vtom(vector<vector<int>>& matr, vector<int>& vec, int m, int n)
{
	for (vector<int>::iterator i = vec.begin(); i != vec.end(); i++)
	{
		vector<vector<int>>::iterator j = matr.begin() + (i - vec.begin()) / n;
		vector<int>::iterator k = j->begin() + (i - vec.begin()) % n;
		*k = *i;
	}
}

void mtov(vector<vector<int>>& matr, vector<int>& vec, int m, int n)
{
	for (vector<vector<int>>::iterator i = matr.begin(); i != matr.end(); i++)
	{
		for (vector<int>::iterator j = i->begin(); j != i->end(); j++)
		{
			vector<int>::iterator k = vec.begin() + ((i - matr.begin()) * n + (j - i->begin()));
			*k = *j;
		}
	}
}


int main(int argc, char* argv[])
{
	ifstream in("task3.txt");
	int m, n;
	in >> m;
	cout << "m = " << m << endl;
	in >> n;
	cout << "n = " << n << endl;

	vector<vector<int>> matr(m, vector<int>(n));
	vector<int> vec(m*n);

	int c;
	for (vector<vector<int>>::iterator i = matr.begin(); i != matr.end(); i++)
	{
		for (vector<int>::iterator j = i->begin(); j != i->end(); j++)
		{
			in >> c;
			*j = c;
		}
	}
	cout << endl;
	cout << "Our matrix: ";
	print_m(matr);
	mtov(matr, vec, m, n);
	cout << "Vector: ";
	print_v(vec);

	for (vector<int>::iterator i = vec.begin(); i != vec.end(); i++)
	{
		in >> c;
		*i = c;
	}
	cout << "Our vector: ";
	print_v(vec);
	vtom(matr, vec, m, n);
	cout << "Matrix: ";
	print_m(matr);

	return 0;
}
