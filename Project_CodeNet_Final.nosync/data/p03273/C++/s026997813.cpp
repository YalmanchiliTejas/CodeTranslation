#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

template<class T, class U>
bool contain(const std::basic_string<T>& s, const U& v)
{
	return s.find(v) != std::basic_string<T>::npos;
}

int  main()
{
	int h, w;
	cin >> h >> w;
	string s[h];
	rep(i, h)
		cin >> s[i];
	
	vector<int> d;
	rep(i, h)
	{
		rep(j, w)
		{
			if(s[i][j] == '.')
				d.push_back(j);
		}
	}

	for (int i = 0; i < h; i++)
	{
		if(contain(s[i], "#"))
		{
			for(int j = 0; j < w; j++)
			{
				if (count(d.begin(), d.end(), j) != h)
					cout << s[i][j];
			}
			cout << endl ;
		}
	}
	return (0);
}
