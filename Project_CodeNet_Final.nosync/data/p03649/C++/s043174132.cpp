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

template <typename T>
istream& operator>>(istream& is, vector<T>& vec) {
    for (T& x: vec) { is >> x; }
    return is;
}

int main() {
	ll ans = 0;
	ll tmp;
	int n; cin >> n;
	vector<ll> a(n);
	cin >> a;
	bool ch = true;
	ll choice[50] = {};
	while(ch){
		ll count = 0;
		REP(i, n) choice[i] = 0;
		REP(i, n){
			if(a[i] >= n){
				ll op = (a[i]-(n-1)+(n-1))/n;
				count += op;
				ans += op;
				choice[i] = op;
				//cout << a[i] << "->" << a[i] - op * n;
				a[i] -= op * n;
			}
		}
		ch = false;
		REP(i, n){
			a[i] += count - choice[i];
			//cout << a[i] << " ";
			if(a[i]>= n) ch = true;
		}
		//cout << endl;
	}
	cout << ans << endl;
}