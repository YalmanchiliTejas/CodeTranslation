#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
const int N = 1e4, M = 7 + 1e9;
int n, d, a[N], dp[N][101][2];
string s;
vector<vector<int> > moves;
int cal(int i, int sum, bool clicked){
	if( i == n )
		return sum % d == 0;
	int &ret = dp[i][sum][clicked];
	if(~ret)
		return ret;
	ret = 0;
	if(!clicked){
		f(j, 0, s[i]-'0')
			ret = (ret + cal(i+1, (sum+j)%d, 1))%M;
		ret = (ret + cal(i+1, (sum+s[i]-'0')%d, 0))%M;
	}
	else
	f(j, 0, 10)
		ret = (ret + cal(i+1, (sum+j)%d, 1))%M;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(0);
   	cin.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> s >> d;
	n = (int)s.size();
	cout << (cal(0, 0, 0) - 1 + M) % M;
}