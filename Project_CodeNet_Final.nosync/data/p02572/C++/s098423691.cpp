#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=200005;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0',ch=getchar();}
    return x*f;
}
const int mod=1e9+7;
int n;
ll a[N],s[N];
void solve()
{
	n=read();
	for(int i=1; i<=n; i++) a[i]=read(),s[i]=s[i-1]+a[i],s[i]%=mod;
	ll ans=0;
	for(int i=2; i<=n; i++) {
		ans+=a[i]*s[i-1]; ans%=mod;
	}
	cout<<ans<<endl;
}
int main()
{
	int T=1;
	while(T--) solve();
}