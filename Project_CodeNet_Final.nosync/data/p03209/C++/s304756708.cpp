#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define FORR(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)

#define CHMIN(a,b) (a)=min((a),(b))
#define CHMAX(a,b) (a)=max((a),(b))

#define DEBUG(x) cout<<#x<<": "<<(x)<<endl

int n;
ll pat[52];
ll siz[52];

int main(){
	cin>>n;
	pat[0] = 1;
	siz[0] = 1;
	FOR(i,1,n+1){
		pat[i] = pat[i-1]*2 + 1;
		siz[i] = siz[i-1]*2 + 3;
	}
	ll x;
	cin>>x;
	ll ans = 0;
	FORR(i,0,n+1){
		if(x == 0)break;
		if(x == siz[i]){
			// eat all
			ans += pat[i];
			break;
		}
		if(x == 1){
			// B
			break;
		}
		assert(i>0);
		if(x <= 1ll + siz[i-1]){
			x--;
		}else{
			ans += 1ll + pat[i-1];
			x -= 1ll + siz[i-1] + 1ll;
		}
	}
	cout<<ans<<endl;
	return 0;
}