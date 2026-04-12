#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define up(i,j,n) for( int i=j;i<=n;i++)
#define down(i,j,n) for( int i=j;i>=n;i--)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define FILE "dealing"
#define ull unsigned int
int read(){
	int x=0,ch=getchar(),f=1;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return f*x;
}

template<class T> bool cmin(T& a,T b){return a>b?a=b,true:false;}
template<class T> bool cmax(T& a,T b){return a<b?a=b,true:false;}
template<class T> T squ(T a){return a*a;}
const int maxn=405000,inf=1000000000,limit=100000,mod=1e9+7;
int add(int a,int b){return (a+=b)>=mod?a-mod:a;}
int sub(int a,int b){return (a-=b)<   0?a+mod:a;}
int mul(int a,int b){return 1LL*a*b%mod;}
int n;
int q[maxn],head,tail;

int main(){
	//freopen(FILE".in","r",stdin);freopen(FILE".out","w",stdout);
	int now=0;
	n=read();
	head=n,tail=n-1;
	up(i,1,n){
		if(!now)q[++tail]=read();
		else q[--head]=read();
		now^=1;
	}
	if(!now)up(i,head,tail)printf("%d%c",q[i],i==tail?'\n':' ');
	else for(int i=tail;i>=head;i--)printf("%d%c",q[i],i==head?'\n':' ');
	return 0;
}



