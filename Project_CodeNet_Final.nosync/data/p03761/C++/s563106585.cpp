#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <iomanip>
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define co(x) cout << x <<endl
#define cs(x) cout << x <<" "
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
using namespace std;
vector<int> mapAlp(string);

int main()
{
	int n;
	cin >> n;
	vector<string> S(n);
	rep(i, n) cin >> S[i];
	vector<int> mapMin = mapAlp(S[0]);
	rep1(i, n-1) 
	{
		vector<int> map = mapAlp(S[i]);
		rep(j, 26)
		{
			mapMin[j] = min(mapMin[j], map[j]);
		}
	}
	string ans;
	rep(i, 26)
	{
		rep(j, mapMin[i])
		{
			ans.push_back((char)('a' + i));
		}
	}
	co(ans);
	return 0;
}

vector<int> mapAlp(string s)
{
	vector<int> res(26, 0);
	rep(i, s.size()) res[s[i] - 'a']++;
	return res;
}