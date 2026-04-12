#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int mod=1e9+7;

int gi() {
	int x=0,o=1;char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') o=-1,ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*o;
}

void inc(int &a,int b) {
	a=a+b>=mod?a+b-mod:a+b;
}

int n,m,f[N];
char s[N];

int main() {
	cin>>n>>m;
	scanf("%s",s+1);
	int p=m+1;
	for(int i=2;i<=m;i++)
		if(s[1]!=s[i]) { p=i;break; }
	if(p==m+1) {
		f[0]=1;
		for(int i=2,s=1;i<=n;i++) {
			f[i]=s;inc(s,f[i-1]);
		}
		int ans=1;
		for(int i=2;i<=n;i++)
			ans=(ans+1ll*i*f[n-i])%mod;
		cout<<ans;
	}
	else {
		--p;int mx=p+!(p&1),len=0;
		for(int i=p+1;i<=m;i++) {
			if(s[i]==s[1]) ++len;
			else {
				if(len&1) mx=min(mx,len);
				len=0;
			}
		}
		++mx;f[0]=1;
		for(int i=2,s=1;i<=n;i+=2) {
			f[i]=s;
			if(i>=mx) inc(s,mod-f[i-mx]);
			inc(s,f[i]);
			//cerr<<i<<' '<<f[i]<<endl;
		}
		int ans=0;
		for(int i=2;i<=mx;i+=2)
			ans=(ans+1ll*i*f[n-i])%mod;
		cout<<ans;
	}
	return 0;
}
