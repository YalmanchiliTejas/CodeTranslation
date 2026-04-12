#include<iostream>
#include<fstream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <random>
#include <set>
using namespace std;
typedef long long ll;


int main(){
	ll n,s,m=998244353,ans=0;
	cin >> n >> s;
	vector<ll> a(n),dp(3001,0),t(3001,0);
	for(auto &&x:a)cin >> x;
	for(auto &&x:a){
		fill(t.begin(), t.end(),0LL);
		for(int i=0;i<3001;i++){
			( t[i] += dp[i] ) %= m;
			if(i+x<=3000)( t[i+x] += dp[i] ) %= m;
		}
		t[0]++;
		t[x]++;
		dp = t;
		( ans += dp[s] ) %= m;
	}
	cout << ans << endl;
}
