#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main(){
	int n,K;cin>>n>>K;
	ll ans=0;
	for(int b=K+1;b<=n;b++){
		int cnt=(b-1-K+1)*(n/b);
		cnt+=max(0,(n%b)-K+1);
		if(K==0)cnt--;
		ans+=cnt;
	}
	cout<<ans<<endl;
}