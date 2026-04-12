#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>


using namespace std;
typedef long long ll;
#define rep(i, s, e) for (int(i) = (s); (i) <= (e); ++(i))
#define all(x) x.begin(),x.end()

int main()
{
	int n; cin >> n;
	vector<vector<int>> alp(n, vector<int>(26, 0));
	string ans; cin >> ans;
	rep(i, 1, n - 1)
	{
		string s; cin >> s;
		for (char x : s)
		{
			++alp[i][x - 'a'];
		}
	}
	sort(all(ans));
	rep(i, 1, n - 1)
	{
		int len = ans.size() - 1;
		string temp = "";
		rep(j, 0, len)
		{
			if (alp[i][ans[j]-'a'] > 0)
			{
				temp += ans[j];
				--alp[i][ans[j] - 'a'];
			}
		}
		ans = temp;
	}
	cout << ans << endl;
}