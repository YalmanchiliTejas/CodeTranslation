#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 998244353
ll ans[500010]={};
int main() {
	ll n,a,k;
	cin>>n>>a>>k;
	map<ll,ll>q;
	ll now=a;
	q[a]++;
	ll cnt=1;
	ll ans=a;
	if(n==1){
		cout <<ans;
		return 0;
	}
	bool ro=false;
	ll rocnt=0;
	ll rozan=0;
	while(true){
		cnt++;
		now*=now;
		now%=k;
		q[now]++;
		ans+=now;
		if(q[now]==3){
			ll zan=n-cnt;
			ans+=zan/rozan*rocnt;
			zan%=rozan;
			cnt=n-zan;
			//cout <<cnt<<endl;
		}		
		if(cnt==n){
			cout <<ans<<endl;
			return 0;
		}		
		if(q[now]==2){
			ro=true;
		}
		if(ro){
			rocnt+=now;
			rozan++;
		}
		//cout <<now<<endl;
	}
	// your code goes here
	return 0;
}