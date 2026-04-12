#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //ai>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //ai>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define REV(x) (reverse(x.begin(),x.end())) //reverse
#define TO(x,t,f) ((x)?(t):(f))
#define CLR(mat) memset(mat, 0, sizeof(mat))
#define FILV(x,a) fill(x.begin(),x.end(),a)
#define FILA(ar,N,a) fill(ar,ar+N,a)
#define NEXTP(x) next_permutation(x.begin(),x.end())
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;else return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
#define pb push_back
#define pri(aa) cout<<(aa)<<endl
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
const ll INF=1e18+7;
const ll MOD=1e9+7;
const ll N = 1007;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,l,r;
	while(1){
		ll ans = 0;
		cin>>n>>l>>r;
		if(n==0&&l==0&&r==0)break;
		vector<ll> a(n);
		FOR(i,0,n){
			cin>>a[i];
		}
		FOR(i,l,r+1){
			bool bl=true;
			FOR(j,0,n){
				if(i%a[j]==0){
					bl=false;
					if(j%2==0)ans++;
					break;
				}
			}
			if(bl&&n%2==0)ans++;
		}
		cout<<ans<<endl;
	}

}
