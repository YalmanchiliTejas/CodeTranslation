#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define repp(i, m, n) for(int i = m; i < n; i++)
#define reps(i, n) for(int i = 1; i <= n; i++)
const int    INF = 100000000;
const double EPS = 1e-10;
const int    MOD = 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int, int> pai;
typedef pair<ll,ll> pal;



int main()
{
	string s;
	cin >> s;
	int ac=0;
	rep(i, s.size()-1)
	{
		if(s[i]=='A'&&s[i+1]=='C') ac=1;
	}
	if(ac==1) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}