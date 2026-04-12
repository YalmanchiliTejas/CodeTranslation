#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,k;cin >> n >> k;
	ll ans=0;
	for(int i=k+1;i<=n;++i){
		ll p=n/i,r=n%i;
		ans+=p*(i-k)+max((ll)0,r+1-k);
	}
	if(k==0) ans-=n;
	cout << ans << endl;
}