#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = ll(A); I < ll(B); ++I)
#define FORR(I,A,B) for(ll I = ll((B)-1); I >= ll(A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //xi>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //xi>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd_(ll a,ll b){if(a%b==0)return b;return gcd_(b,a%b);}
ll lcm_(ll a,ll b){ll c=gcd_(a,b);return ((a/c)*b);}
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=ll(1e16)+ll(7);
const ll MOD=1000000007LL;
#define out(a) cout<<fixed<<setprecision((a))
//tie(a,b,c) = make_tuple(10,9,87);
#define pop_(a) __builtin_popcount((a))
ll keta(ll a){ll r=0;while(a){a/=10;r++;}return r;}



int main(){
	ll N,X,M;
	cin >> N >> X >> M;

	//今iにいて2^j個先に行ったとき

	ll pla[M][35]={},bal[M][35]={};

	FOR(i,0,M){
		pla[i][0] = i*i % M;
		bal[i][0] = i*i % M;
	}
	FOR(j,1,35)FOR(i,0,M){
		pla[i][j] = pla[ pla[i][j-1] ][j-1];
		bal[i][j] = bal[i][j-1] + bal[ pla[i][j-1] ][j-1];
	}

	ll ans = X;
	N--;
	FOR(i,0,35){
		if(N&(1LL<<i)){
			ans += bal[X][i];
			X = pla[X][i];
		}
	}
	cout << ans << endl;

}
