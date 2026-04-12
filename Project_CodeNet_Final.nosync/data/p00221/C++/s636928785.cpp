#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <sstream>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define repp(i,k,n) for(int i=k;i<(int)n;i++)
#define re(n) for(int i=0;i<(int)n;i++)

string fizz(int now)
{
	if (now % 15 == 0)return "FizzBuzz";
	if (now % 5 == 0)return "Buzz";
	if (now % 3 == 0)return "Fizz";
	stringstream st; st << now;
	return st.str();
}



int main()
{
	int m, n;
	while (cin >> m >> n&&n)
	{
		vector<int> a;
		re(m)a.push_back(i + 1);
		vector<int>::iterator it = a.begin();

		for (int now = 1; now<=n; now++)
		{
			string st;
			cin >> st;
			if (a.size()>=2&&st!=fizz(now))
			{
				it = a.erase(it);
				if (it == a.end())it = a.begin();
			}
			else 
			{
				if (it == a.end() - 1)it = a.begin();
				else it++;
			}
		}
		for (int i = 0; i < a.size(); i++)cout << (i == 0 ? "" : " ") << a[i];
		cout << endl;
	}
}