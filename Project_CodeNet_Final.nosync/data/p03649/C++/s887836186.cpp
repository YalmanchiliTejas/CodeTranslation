#include<iostream>
#include<algorithm>

using namespace std;

#define fr(i,a,b) for(int i=a;i<b;++i)
typedef long long ll;
/////////////////////////

int const N = 141;

ll a[N];
int n;

void solve(){
	cin >> n;
	fr(i, 0, n) cin >> a[i];

	ll ans = 0;
	bool f = true;
	while(f){
		f = false;
		int maxii = 0;
		fr(i, 0, n) if(a[i] > a[maxii]){
			maxii = i;
		}
		ll add = a[maxii] / n;
		ans += add;
		a[maxii] %= n;
		fr(i, 0, n){
			if(i != maxii) a[i] += add;
		}
		if(add > 0) f = true;
	}
	cout << ans << endl;
}

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	solve();


	return 0;
}