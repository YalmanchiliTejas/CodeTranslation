#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define FORR(I,A,B) for(int I = ((B)-1); I >= (A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define REV(x) (reverse(x.begin(),x.end())) //reverse
int gcd(int a,int b){if(a<b)swap(a,b);if(a%b==0)return b;return gcd(b,a%b);}
int lcm(int a,int b){int c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=1e18+7;
const ll MOD=1e9+7;
#define pri(a) cout << (a) << endl

P m[51];
ll ans;
void dfs(ll n,ll k){
	if(k<=0)return;
	if(n==1){
		if(k==5)ans +=3ll; 
		else ans += k-1ll;
		return;
	}
	ll leveln = m[n].first + m[n].second;
	if(k==leveln){
		ans += m[n].second;
	}else if(k==(leveln/2ll+1ll)){
		ans += m[n-1].second+1ll;
		return;
	}else if(k < (leveln/2ll+1ll)){
		dfs(n-1,k-1);
	}else{
		ans += m[n-1].second+1ll;
		dfs(n-1,k-1ll-leveln/2ll);
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ans = 0;
	ll n,x;
	cin >> n >> x;
	m[0] = {0ll,1ll};
	FOR(i,1,51)m[i]={m[i-1].first*2ll+2ll,m[i-1].second*2ll+1ll};//{b,p}
	dfs(n,x);
	cout << ans << endl;
}