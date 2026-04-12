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

	ll amari[m];
	rep(i,m){
		amari[i] = i*i%m;
	} 

	ll ans = 0;
	ll when[100010];
	fill(when,when+m,-1);
	ll a[100010];
	rep(i,100010){
		if (i==0){
			a[0] = x;
			when[x] = i;
		}else {
			a[i] = amari[a[i-1]];
			if (when[a[i]]==-1){
				when[a[i]] = i;
			}else {
				int loopstart = when[a[i]];
				int loopend = i-1;

				if (n<i){
					ll ans = 0;
					rep(j,n){
						ans += a[j];
					}
					cout << ans << endl;
					return 0;
				}

				ll sumbefloop = 0;
				rep(j,loopstart){
					sumbefloop += a[j];
				}
				ll loopsum = 0;
				for (int j=loopstart;j<=loopend;j++){
					loopsum += a[j];
				}

				ll tmp = n-loopstart;
				ll z = tmp/(loopend-loopstart+1);
				ans = sumbefloop+loopsum*z;
				ll v = tmp%(loopend-loopstart+1);
				for (int j=loopstart;j<loopstart+v;j++){
					ans += a[j];
				}
				cout << ans << endl;
				return 0;
			}
		}
	}
}
