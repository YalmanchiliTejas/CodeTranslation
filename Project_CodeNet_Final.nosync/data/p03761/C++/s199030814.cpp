#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <iomanip>
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
ll mod = 1e9 + 7;

using namespace std;
using Graph = vector<vector<int>>;
Graph G;

int cnt_digit(ll N)
{
	int digit = 0;

	while (N > 0)
	{
		N /= 10;
		digit++;
	}
	return digit;
}


int main()
{
	ll n;
	cin >> n;
	vector<string> S(n);
	for (int i = 0; i < n; i++)
	{
		cin >> S[i];
	}

	string ans;
	for (char c = 'a'; c <= 'z'; c++)
	{
		int small = 100000;
		for (int i = 0; i < n; i++)
		{
			int cnt = 0;
			for (int j = 0; j < S[i].length(); j++)
			{
				if (S[i][j] == c)
				{
					cnt++;
				}
			}
			small = min(small, cnt);
		}
		for (int i = 0;i < small;i++)
		{
			ans += c;
		}
	}
	
	cout << ans << endl;
	return 0;
}
