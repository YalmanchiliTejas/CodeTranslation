#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = int(A); I < int(B); ++I)
#define FORR(I,A,B) for(ll I = int((B)-1); I >= int(A); --I)
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


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll N,Q,a,b;
	cin >> N >> Q;
	vector<ll> v(N+2,-1);
	FOR(i,1,N+1)v[i]=i;
	set<ll> se;
	se.insert(1);
	se.insert(2);
	FOR(i,0,Q){
		cin >> a >> b;
		swap(v[a],v[b]);
		if(v[a]==1){
			se.insert(v[a-1]);
			se.insert(v[a+1]);
		}
		if(v[b]==1){
			se.insert(v[b-1]);
			se.insert(v[b+1]);
		}
		if(v[a-1]==1||v[a+1]==1){
			se.insert(v[a]);
		}
		if(v[b-1]==1||v[b+1]==1){
			se.insert(v[b]);
		}
	}
	ll m = se.count(-1);
	cout << se.size() - m << endl;

}