//QWsin
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define out(i,u) for(int i=first[u];i!=-1;i=nxt[i])
#define repvc(i,vc) for(int i=0,Sz=vc.size();i<Sz;++i)
using namespace std;
inline int read()
{
	char ch=getchar();int ret=0,f=1;
	while(ch<'0' || ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	for(;ch>='0' && ch<='9';ch=getchar()) ret=ret*10+ch-'0';
	return ret*f;
}

inline void print(string name,int *arr,int len){
	rep(i,1,len) printf("%s[%d]=%d\n",name.c_str(),i,arr[i]);puts("");
}
inline void print(string name,int a){
	printf("%s=%d\n",name.c_str(),a);puts("");
}

typedef long long ll;
const int INF=1<<30;

const int maxn=200000+10;

int a[maxn],dp[maxn],t[maxn];
int main()
{
	int n;cin>>n;
	rep(i,1,n) a[i]=read();
	int l=0;
	for(int i=n;i>=1;--i)
	{
		if(a[i]>=t[l]) t[++l]=a[i];
		else{
			int pos=upper_bound(t+1,t+l+1,a[i])-t;
			if(t[pos]==a[i]) ++pos;
			t[pos]=a[i];
			l=max(l,pos);
		}
	}
	cout<<l<<endl;
	return 0;
}
