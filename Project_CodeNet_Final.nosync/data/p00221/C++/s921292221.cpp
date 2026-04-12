#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int N, M;

	while (cin >> M >> N, M||N)
	{
		vector<int> a;
		for (int i=1; i<=M; i++)
			a.push_back(i);

		int p = 0;
		int num = 1;
		while (N--)
		{
			
			string s;
			cin >> s;

			if (a.size() == 1) continue;
			if (num%3 == 0 && num%5 == 0)
			{
				if (s != "FizzBuzz")
				{
					a.erase(a.begin()+p);
					p--;
				}
			}
			else if (num%3 == 0)
			{
				if (s != "Fizz")
				{
					a.erase(a.begin()+p);
					p--;
				}
			}
			else if (num%5 == 0)
			{
				if (s != "Buzz")
				{
					a.erase(a.begin()+p);
					p--;
				}
			}
			else
			{
				if (atoi(s.c_str()) != num)
				{
					a.erase(a.begin()+p);
					p--;
				}
			}

			p++;
			num++;
			if (p >= a.size())
				p = 0;
		}

		for (int i=0; i<a.size(); i++)
		{
			cout << a[i];
			if (i != a.size()-1)
				cout << ' ';
		}
		cout << endl;
	}

	return 0;
}