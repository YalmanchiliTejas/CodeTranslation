#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define FORR(I,A,B) for(ll I = (B-1); I >= (A); --I)
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;else return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=1e18+7;
const ll MOD=1e9+7;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(1){
		ll n;
		cin >> n;
		if(n==0)break;
		ll maxk = 0;
		ll mink = INF;
		ll ans = 0;
		FOR(i,0,n){
			ll k;
			cin >> k;
			maxk = max(maxk,k);
			mink = min(mink,k);
			ans += k;
		} 
		ans -= (maxk+mink);
		cout << ans/(n-2) << endl;
	}
}
