// _______  _____  _______  _____  _______ _______ _____ _______ _____ _    _ _______ 
// |       |     | |  |  | |_____] |______    |      |      |      |    \  /  |______ 
// |_____  |_____| |  |  | |       |______    |    __|__    |    __|__   \/   |______ 
//
//  _____   ______  _____   ______  ______ _______ _______ _______ _____ __   _  ______   /
// |_____] |_____/ |     | |  ____ |_____/ |_____| |  |  | |  |  |   |   | \  | |  ____  / 
// |       |    \_ |_____| |_____| |    \_ |     | |  |  | |  |  | __|__ |  \_| |_____| .  
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define FOR(I,A,B) for(int I = int(A); I < int(B); ++I)
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //ai>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //ai>v  x is sorted
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
const ll INF=1e18+7;
const ll MOD=1e9+7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll N,K,ans=0;
	cin >> N >> K;
	if(K==0){
		cout << N*N << endl;
		return 0;
	}
	FOR(b,K+1,N+1){
		ll n = N/b;
		ans += n*(b-K);
		if(N>=b*n+K){
			ans += N-b*n-K+1;
		}
	}
	cout << ans << endl;
}