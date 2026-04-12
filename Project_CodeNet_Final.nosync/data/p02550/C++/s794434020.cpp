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
	ll ans = 0;

	vector<ll> did(M+9,0),sum(M+9,0);
	ll b = M;

	while(N>0){
		if(did[X]){
			ll loop_point = sum[b] - sum[X] + X;
			if(b==X){
				ans += X*N;
				cout << ans << endl;
				return 0;
			}
			ans += loop_point * ( N / (did[b]-did[X]+1) );
			N %= (did[b]-did[X]+1);
		}

		if(N>0){
			did[X] = did[b] + 1;
			N--;
			ans += X;
			sum[X] = sum[b] + X;
			b = X;
			X = X*X%M;
		}

		if(X==0)break;

	}


	cout << ans << endl;

}
