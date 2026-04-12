#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 105
int a[N];
int sol(int x,int n)
{
	if(x==n) return 0;
	int ans=0;
	for(int i=x+1;i<n;i++) ans+=9*(n-i)*9;
	ans+=(a[x]-1)*9*(n-x);
	int cur=x+1;
	while(cur<=n&&a[cur]==0) cur++;
	if(cur!=n+1)
	{
		ans+=(n-cur)*9;
		ans+=a[cur];
	}
	return ans;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	string s;
	cin>>s;
	int n=s.length();
	for(int i=1;i<=n;i++) a[i]=s[i-1]-'0';
	int k=read();
	if(k==1)
	{
		int ans=9*(n-1);
		ans+=a[1];
		cout<<ans<<endl;
	}
	if(k==2)
	{
		int ans=0;
		if(n==1)
		{
			cout<<"0\n";
			return 0;
		}
		for(int i=2;i<n;i++) ans+=9*(i-1)*9;
		ans+=(a[1]-1)*9*(n-1);
		int cur=2;
		while(cur<=n&&a[cur]==0) cur++;
		if(cur!=n+1)
		{
			ans+=(n-cur)*9;
			ans+=a[cur];
		}
		cout<<ans<<endl;
	}
	if(k==3)
	{
		if(n<=2)
		{
			cout<<"0\n";
			return 0;
		}
		int ans=0;
		for(int i=3;i<n;i++) ans+=9*9*9*(i-1)*(i-2)/2;
		ans+=(a[1]-1)*9*9*(n-1)*(n-2)/2;
		int cur=2;
		while(cur<=n&&a[cur]==0) cur++;
		{
			ans+=sol(cur,n);
		}
		cout<<ans<<endl;
	}
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}

