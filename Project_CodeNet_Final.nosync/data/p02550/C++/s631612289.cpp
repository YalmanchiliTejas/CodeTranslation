#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int len=0;
ll a[100004],d[100004];
ll N;
ll M;
int vis[100004],st;
int main(){
	len=1;
	cin>>N>>a[1]>>M;
	d[1]=a[1];
	while(1){
		len++;
		a[len]=a[len-1]*a[len-1]%M;
		if(vis[a[len]]){
			st=vis[a[len]];
			len--;
			break;
		}
		vis[a[len]]=len;
		d[len]=d[len-1]+a[len];
	}
	ll ans=0;
	for(int i=1;i<st;i++){
		N--;
		ans+=a[i];
	}
	int lenl=len-st+1;
	ans+=N/lenl*(d[len]-d[st-1]);
	cout<<ans+d[N%lenl+st-1]-d[st-1];
}