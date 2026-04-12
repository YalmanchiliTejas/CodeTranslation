#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<ll, ll> pii;
typedef vector<ll> VL; const int MD = 1e9 + 7;
void dbg(){cerr<<"\n";} template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }


int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	string s; int k;
	cin >>s >>k;

	vector<VL> dp(5, VL(2));
	dp[0][0] = 1;
	rep(i, sz(s)){
		vector<VL> np(5, VL(2));
		rep(j, k+1) rep(d, 10){
			int nj = j + (d>0);
			if(d < s[i]-'0') np[nj][1] += dp[j][0];
			else if(d==s[i]-'0') np[nj][0] += dp[j][0];
			np[nj][1] += dp[j][1];
		}
		swap(dp, np);
	}
	cout << dp[k][0] + dp[k][1] <<"\n";
	return 0;
}
