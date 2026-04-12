#include <bits/stdc++.h>
#define  rep(i,a,b)for(int i=a;i<b;++i)
#define  rrep(i,a,b)for(int i=a;i>=b;--i)
#define  yesno(flag)if(flag)cout<<"Yes"<<endl; else cout<<"No"<<endl;
using namespace std;
typedef long long ll;
const int INF=1000000000LL;
const ll r197=1000000007;
typedef pair<int,int>P;
typedef pair<int,P>Pa;

int main() {
	ll n,k;
	ll ans=0;
	cin>>n>>k;
	rep(i,k+1,n+1){
		ll s=0;
		while(1){
			if(i*s+k<=n){
				if(s==0&&k==0)ans--;
				ans+=min(n-i*s-k+1,i-k);
			}else break;
			s++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
