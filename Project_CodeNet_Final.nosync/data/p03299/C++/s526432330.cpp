#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
const int N=205;
const int Gi=(P+1)/2;
#define ll long long
ll fsp(ll x,int y){
	ll ans=1;
	while(y){
		if(y&1)	ans=ans*x%P;
		x=x*x%P,y>>=1;
	}
	return ans;
}
ll f[N][2];
vector<int>ch[N];
int n,top,a[N],st[N],len[N];
void dp(int x,int fl){
	int si=ch[x].size();
	for(int i=0;i<si;i++)	dp(ch[x][i],a[x]);
	if(!si){
		f[x][0]=fsp(2,len[x])-2;
		f[x][1]=fsp(2,a[x]-fl);
	}
	else{
		ll r1=1,r2=1;
		for(int i=0;i<si;i++){
			r1=r1*(f[ch[x][i]][0]+f[ch[x][i]][1]*2)%P;
			r2=r2*f[ch[x][i]][1]%P;
		}
		f[x][0]=((r1-r2+P)*fsp(2,len[x])+r2*(fsp(2,len[x])-2))%P;
		f[x][1]=r2*fsp(2,a[x]-fl)%P;
	}
}
int main(){
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]),len[i]=1;
	for(int i=1;i<=n;i++){
		while(top&&a[st[top]]>=a[i]){
			if(a[st[top]]==a[i])	len[i]+=len[st[top]],swap(ch[st[top]],ch[i]);
			else{
				if(a[st[top-1]]>=a[i])	ch[st[top-1]].push_back(st[top]);
				else	ch[i].push_back(st[top]);
			}
			top--;
		}
		st[++top]=i;
	}
	while(top>1)	ch[st[top-1]].push_back(st[top]),top--;

	dp(st[top],0);
	printf("%lld\n",(f[st[1]][0]+f[st[1]][1])%P);
	return 0;
}
