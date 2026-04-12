//abc179_e.cpp
//Sat Sep 19 22:12:48 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007
#define rep(i,n) for (ll i=0;i<(n);++i)

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	ll n,x,m;
	cin >> n >> x >> m;

	if (x==0){
		cout << 0 << endl;
		return 0;
	}

	ll amari[m];
	rep(i,m){
		amari[i] = i*i%m;
//		cout << i << " " << amari[i] << endl;
	} 

	ll ans = 0;
	ll when[m];
	fill(when,when+m,-1);
	ll prev = -1;
	vector<ll> sum;
	sum.push_back(0);
	rep(i,m){
		if (i==0){
			prev = x;
			when[x] = i;
			sum.push_back(prev);
		}else {
			prev = amari[prev];
			if (when[prev]==-1){
				when[prev] = i;
				sum.push_back(sum[i]+prev);
			}else {
				// if (i==1){
				// 	cout << sum[1]*n << endl;
				// 	return 0;
				// }
				int loopstart = when[prev];
				int loopend = i-1;
				ll loopsum = sum[i]-sum[loopstart];
				ll sumbefloop = sum[loopstart];
				if (n<i){
					cout << sum[n] << endl;
					return 0;
				}
				ll tmp = n-loopstart;
				ll z = tmp/(i-loopstart);
				ans = sumbefloop+loopsum*z;
				ll v = tmp%(i-loopstart);
				ans += sum[loopstart+v]-sum[loopstart];
				cout << ans << endl;
				return 0;
			}
		}
	}
}
