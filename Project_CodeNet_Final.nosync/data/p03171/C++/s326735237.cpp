#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll a=0,b=getchar(),c=1;
	while(!isdigit(b))c=b=='-'?-1:1,b=getchar();
	while(isdigit(b))a=a*10+b-'0',b=getchar();
	return a*c;
}
void print(ll x){
	if(x<0)putchar('-'),x=-x;
	int y=x%10+'0';
	if(x>=10)print(x/10);
	putchar(y);
}
ll n,a[3005],dp[3005][3005];
ll gao(int x,int y){
	if(x==y)return dp[x][y]=a[x];
	if(dp[x][y]<1e15)return dp[x][y];
	return dp[x][y]=max(a[x]-gao(x+1,y),a[y]-gao(x,y-1));
}
int main(){
	memset(dp,0x3f,sizeof(dp));
	n=read();
	for(int i=0;i<n;i++)
		a[i]=read();
	print(gao(0,n-1));
    return 0;
}