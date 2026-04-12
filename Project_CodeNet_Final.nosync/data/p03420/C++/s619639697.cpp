#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF=1e9;
const long double eps=1e-9;
inline ll read(){
	ll x=0,flag=1;
	char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')flag=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x*flag;
}
int main(){
	ll i,j,k,m,n,ans=0;
	n=read();k=read();
	for(i=1;i<=n;i++)ans+=(n/i)*(max(0ll,i-k))+max(0ll,n%i-k+1);
	if(k==0)ans-=n;
	printf("%lld\n",ans);
	return 0;
}
