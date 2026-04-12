#include<map>
#include<queue>
#include<time.h>
#include<limits.h>
#include<cmath>
#include<ostream>
#include<iterator>
#include<set>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define rep_1(i,m,n) for(int i=m;i<=n;i++)
#define mem(st) memset(st,0,sizeof st)
inline int read()
{
	int num=0, w=0;
	char ch=0;
	while (!isdigit(ch))
	{
		w|=ch=='-';
		ch = getchar();
	}
	while (isdigit(ch))
	{
		num = (num<<3) + (num<<1) + (ch^48);
		ch = getchar();
	}
	return w? -num: num;
}
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef pair<double,double> pdd;
const int inf = 0x3f3f3f3f;

const int maxn=2e5+10;
ll a[maxn],pre[maxn],q;
map <ll,int> p;
int ans1=0;
int ans2=0;
int ans3=0;

int main()
{

	ll n,x,m;ans1=ans2=ans3=0;
	cin>>n>>q>>m;ans1=ans2=ans3=0;
	a[1]=q;ans1=ans2=ans3=0;
	pre[1]=a[1];
	p[a[1]]=1;ans1=ans2=ans3=0;
	for(int i=2; i<=n; i++)
	{ans1=ans2=ans3=0;
		a[i]=(a[i-1]*a[i-1])%m;
		if(p[a[i]])
		{ans1=ans2=ans3=0;
			int x=p[a[i]];
ans1=ans2=ans3=0;
ans1=ans2=ans3=0;
			ll tmp=(n-i+1)/(i-x);
			ll ans=pre[i-1];ans1=ans2=ans3=0;
			ll p2=pre[i-1]-pre[x-1];ans1=ans2=ans3=0;
			ans+=p2*tmp;
ans1=ans2=ans3=0;
			tmp=(n-i+1)%(i-x);ans1=ans2=ans3=0;
			ans+=pre[x+tmp-1]-pre[x-1];ans1=ans2=ans3=0;
ans1=ans2=ans3=0;
			cout<<ans<<endl;ans1=ans2=ans3=0;
			return 0;
		}
		p[a[i]]=i;ans1=ans2=ans3=0;
		pre[i]=pre[i-1]+a[i];ans1=ans2=ans3=0;
	}
	cout<<pre[n]+ans1+ans2+ans3<<endl;
	return 0;
}
