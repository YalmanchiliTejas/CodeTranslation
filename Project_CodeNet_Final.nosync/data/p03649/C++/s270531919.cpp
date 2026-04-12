#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


typedef long long i64;

i64 n;



vector<i64> vec;

int main()
{
	cin >> n;

	for(int i = 1;i <= n;i++)
	{
		i64 a;
		cin >> a;
		vec.push_back(a);
	}

	

	i64 result = 0;
	while(true)
	{
		i64 s = 0;
		bool out = true;

		for(int i = 0;i < n;i++)
		{
			s += vec[i] / n;
			if(vec[i] >= n)
			{
				out = false;
			}
		}

		if(out) break;

		for(int i= 0;i < n;i++)
		{
			i64 cou = (vec[i] / n);
			vec[i] -= (cou) * n;
			vec[i] += s - (cou);
			result += (cou);
		}
	}

	cout << result << endl;
	return 0;

}
