#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define vcout(v) rep(i,v.size()) cout << v[i] << " "; cout << endl
#define mcout(m) rep(j,m.size()){vcout(m[j]);}
const ll MOD = 1e9 + 7;

void mainsolve(){

	string s;
	cin >> s;
	ll k;
	cin >> k; 


	ll dp[105][2][105];
	// 1桁目
	ll first = s[0] - '0';
	rep(i,first+1) dp[0][i < first][i != 0]++;
	
	// 2桁目以降
	rep(i,s.size()-1) rep(j,2) rep(kk,105){
		ll lim = j? 9 : s[i+1] - '0';
		rep(next, lim+1){
			ll tmp = 0;
			if(next != 0) tmp++;
			dp[i+1][j || next < lim][kk + tmp] += dp[i][j][kk];
		}
	}

	cout << dp[s.size()-1][true][k] + dp[s.size()-1][false][k] << endl;
	// rep(i,2) rep(kk,3) cout << dp[i][false][kk] << endl;

	return;
}

int main(){
	
	//ll TC;cin>>TC;rep(I,TC){cout<<"case:"<<I+1<<"---"<<endl; // comment out!
		mainsolve();
	//} // comment out!
	return 0;
}
