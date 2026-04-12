#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pa;
typedef unsigned int uint;
typedef unsigned long long ull;
#define w1 first
#define ls (x<<1)
#define w2 second
#define ins insert
#define rs (x<<1|1) 
#define mp make_pair
#define pb push_back
#define mid ((l+r)>>1)
#define sqr(x) ((x)*(x))
#define cle(x) ((x).clear())
#define lowbit(x) ((x)&(-x))
#define SZ(x) (int((x).size()))
#define ms(x,y) memset(x,y,sizeof (x))
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define rep2(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define per(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define Rep(p,x) for(int (p)=head[(x)];(p);(p)=nxt[(p)]) 
#define Rep2(p,x) for(int (p)=cur[(x)];(p);(p)=nxt[(p)])
#define debegin printf("debug\nbegin\n")
#define deend printf("debug\nend\n")
#define isfind printf("find\n")
template<class T>inline void rread(T&num){
	num=0;T f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
	num*=f;
}
inline int getgcd(int x,int y){if(!x)return y;return getgcd(y%x,x);}
inline int power(int x,int k,int p){int res=1;for(;k;k>>=1,x=(ll)x*x%p)if(k&1)res=(ll)res*x%p;return res;}
const double pi=acos(-1);
inline void judge(){
	freopen("input.txt","r",stdin);
} 
//********************************head*************************************
const int maxn=1e5+5;
int n,tot,rt,flag;
int head[maxn],des[maxn<<1],nxt[maxn<<1];
inline void adde(int x,int y){
	des[++tot]=y;nxt[tot]=head[x];head[x]=tot;
}
inline int dfs(int x,int fa){
	int cnt=0;
	Rep(p,x)if(des[p]!=fa)cnt+=dfs(des[p],x);
	if(flag)return 0;
	if(!cnt)return 1;
	if(cnt==1)return 0;
	flag=1;
	return 0;
}
int main(){
	rread(n);
	rep(i,1,n-1){
		int x,y;rread(x);rread(y);
		adde(x,y);adde(y,x);
	}
	if(dfs(1,0)==1&&(!flag))flag=1;
	if(flag)puts("First");
	else puts("Second");
	return 0;
}