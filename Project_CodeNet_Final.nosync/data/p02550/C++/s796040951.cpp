//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF INT_MAX
#define LLINF LLONG_MAX
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007
#define MODB  998244353 

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
    for (T& x: vec) { is >> x; }
    return is;
}

int main() {
	ll ans = 0;
	ll tmp;
	ll n; cin >> n;
	ll x , m; cin >> x >> m;
	ll co[m] = {};
	ll now = 1, here = x;
	ll rot, st;
	while(1){
		if(co[here] !=0){
			rot = now - co[here];
			st = co[here];
			break;
		}
		co[here] = now;
		now ++;
		here = (here*here)%m;
	}
	ll rop;
	ll rest;
	if(st + rot < n){
		rop = (n - st + 1) / rot;
		rest = st - 1 + (n - st + 1) % rot;
	}
	else{
		rop = 0;
		rest = n;
	}
	now = 1, here = x;
	while(1){
		if(co[here] != now){
			break;
		}
		if(now <= rest) ans += here;
		if(co[here] < st) tmp = 0;
		else tmp += here;
		now ++;
		here = (here*here)%m;
	}
	//cout << rest << " " <<  ans << " " << rop << " " << tmp << endl;
	cout << ans + (ll)rop * (ll)tmp << endl;
}