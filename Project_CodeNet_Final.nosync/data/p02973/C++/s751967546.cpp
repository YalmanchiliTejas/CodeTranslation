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
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=1e18+7;
const ll MOD=1e9+7;
#define out(a) cout<<fixed<<setprecision((a))

ll LIS(vector<ll> a){
	vector<ll> dp;
	const ll infi=1e9+7;
	ll n = a.size();
	dp.resize(n);
	fill(dp.begin(),dp.end(),infi);
	for(int i=0;i<n;i++){
		*upper_bound(dp.begin(),dp.end(),a[i])=a[i];
	}
	ll ans = lower_bound(dp.begin(),dp.end(),infi)-dp.begin();
	return ans;
}


int main(){
	ll N;
	cin >> N;
	vector<ll> A(N);
	FOR(i,0,N)cin>>A[i];
	FOR(i,0,N)A[i]*=-1;
	cout << LIS(A) << endl;
}
