#include<iostream>
#include<string>
using namespace std;

string L, M, U;
long long a, b, c;
char T[11] = "0123456789";

int main() {
	cin >> L >> a;
	for (int i = 0; i < 10; i++)
	{
		if (L[0] == T[i])
		{
			b = i; c = i;
		}
	}
	if (L[1] == '*')
	{
		U += L[0];
		b = 0;
	}
	for (int i = 1; i < L.size(); i += 2)
	{
		int d;
		for (int j = 0; j < 10; j++)
		{
			if (L[i + 1] == T[j])
			{
				d = j;
			}
		}
		if (L[i] == '+')
		{
			c += d;
		}
		if (L[i] == '*')
		{
			c *= d;
		}
	}
	for (int i = 1; i < L.size(); i += 2)
	{
		int d, e;
		for (int j = 0; j < 10; j++)
		{
			if (L[i + 1] == T[j])
			{
				d = j;
			}
		}
		if (L[i] == '+')
		{
			if (U.size() >= 1)
			{
				e = 1;
				for (int j = 0; j < U.size(); j++)
				{
					for (int k = 0; k < 10; k++)
					{
						if (U[j] == T[k])
						{
							e *= k;
						}
					}
				}
				b += e;
			}
			U = "";
			if (i == L.size() - 2)
			{
				b += d;
			}
			else {
				if (L[i + 2] == '+')
				{
					b += d;
				}
				else
				{
					for (int j = 0; j < 10; j++)
					{
						if (L[i + 1] == T[j])
						{
							U += T[j];
						}
					}
				}
			}
		}
		if (L[i] == '*')
		{
			U += L[i + 1];
		}
	}
	if (U.size() >= 1)
	{
		int e = 1;
		for (int j = 0; j < U.size(); j++)
		{
			for (int k = 0; k < 10; k++)
			{
				if (U[j] == T[k])
				{
					e *= k;
				}
			}
		}
		b += e;
	}
	if (b == a && c == a) { cout << 'U' << endl; }
	if (b == a && c != a) { cout << 'M' << endl; }
	if (b != a && c == a) { cout << 'L' << endl; }
	if (b != a && c != a) { cout << 'I' << endl; }
	return 0;
}