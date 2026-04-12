#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll a[51],p[51],n,k,ans;

void dep(ll now){
	if(k<=0){
		return;
	}		
	if(now==0){
		
		ans++;
		k--;
		return;
	}
	ll next=a[now-1];
	k--;
	if(k<=0){
		return;
	}	
	if(k>=next){
		k-=next;
		ans+=p[now-1];
	}
	else{
		dep(now-1);
	}
	if(k<=0){
		return;
	}	
	ans++;k--;
	if(k<=0){
		return;
	}
	if(k>=next){
		k-=next;
		ans+=p[now-1];
	}
	else{
		dep(now-1);
	}
	if(k<=0){
		return;
	}	
	k--;	if(k<=0){
		return;
	}
}
int main() {
	cin>>n>>k;
	a[0]=p[0]=1;
	for(int i=1;i<51;i++){
		a[i]=2*a[i-1]+3;
		p[i]=2*p[i-1]+1;
	}
	dep(n);
	cout <<ans;
	// your code goes here
	return 0;
}