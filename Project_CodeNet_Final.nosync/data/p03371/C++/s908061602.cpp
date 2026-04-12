#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ldb;
#define pi acos(-1)
const int N=100005;
const ll mod=1e9+9;
inline ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
int a,b,c,x,y;
int ans;
int main()
{
	a=read();b=read();c=read();x=read();y=read();
	if(c+c<a+b){
		int tmp=min(x,y),ans2=2*max(x,y)*c;
		ans=tmp*2*c;
		x-=tmp;y-=tmp;
		if(x)
			ans+=x*a;
		else if(y)
			ans+=y*b;
		ans=min(ans2,ans);
	}
	else
		ans=a*x+b*y;
	cout<<ans;
	return 0;
}