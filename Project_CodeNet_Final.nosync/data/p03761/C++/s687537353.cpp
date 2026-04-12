#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;




int main()
{
	int n;
	cin >> n;
	vector<string> S(n);
	rep(i,n)cin >> S[i];
	vector<vector<int>> alph(n,vector<int>(26));
	rep(i,n)
	{
		rep(j,S[i].size())
		{
			alph[i][S[i][j]-'a']++;
		}
	}

	rep(i,n-1)
	{
		rep(j,26)
		{
			alph[i+1][j] = min(alph[i+1][j],alph[i][j]);
		}
	}

	rep(i,26)
	{
		rep(j,alph[n-1][i])
		{
			cout<<(char)('a'+i);
		}
	}
	cout<<endl;


	return 0;
}