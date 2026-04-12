#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define vcout(v) rep(i,v.size()) cout << v[i] << " "; cout << endl
#define mcout(m) rep(j,m.size()){vcout(m[j]);}

void mainsolve(){
	// S - digit sum

	const ll MOD = 1e9 + 7;
	string s;
	cin >> s;
	vector<ll> ss(s.size());
	rep(i,s.size()) ss[i] = s[i] - '0';
	ll d;
	cin >> d;

	ll dp[ss.size()][2][d];
	memset(dp,0,sizeof(dp));

	rep(i,10){
		if(i<ss[0]) dp[0][1][i%d]++;
		else if(i==ss[0]) dp[0][0][i%d]++;
	}

	rep(i,ss.size()-1) rep(j,2) rep(k,d) {
		ll nn; j == 1 ? nn=10 : nn=ss[i+1]+1; 
		rep(next,nn){ 
			(dp[i+1][j || (next<ss[i+1])][(k+next)%d] += dp[i][j][k]) %= MOD;
		}
	}

	ll res = (dp[ss.size()-1][0][0] + dp[ss.size()-1][1][0]) % MOD;
	cout << (res - 1 + MOD) % MOD << endl;
	return;
}

int main(){
	
	// TC;cin>>TC;rep(I,TC){cout<<"case:"<<I+1<<"---"<<endl; // comment out!
	mainsolve();
	//// comment out!
	return 0;
}