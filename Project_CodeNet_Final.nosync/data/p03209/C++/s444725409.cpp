#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll n,k,ans,cnt,p[51],sum[51];
void dep(ll now){
	if(cnt>=k){
		return;
	}
	if(now==0){
		ans++;
		cnt++;
		return;
	}
	cnt++;
	if(cnt+sum[now-1]<=k){
		cnt+=sum[now-1];
		ans+=p[now-1];
	}
	else{
	dep(now-1);
	}
	if(cnt>=k){
		return;
	}	
	ans++;cnt++;
	if(cnt>=k){
		return;
	}
	if(cnt+sum[now-1]<=k){
		cnt+=sum[now-1];
		ans+=p[now-1];
	}
	else{
	dep(now-1);
	}
	if(cnt>=k){
		return;
	}		
	cnt++;
}
int main() {
	p[0]=sum[0]=1;
	for(ll i=1;i<51;i++){
		p[i]=2*p[i-1]+1;
		sum[i]=2*sum[i-1]+3;
	}
	cin>>n>>k;
	dep(n);
//	cout <<cnt<<endl;
	cout <<ans;
	// your code goes here
	return 0;
}