#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#define ll long long
#define mp make_pair
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define r0p(i,n) for(int i=0;i<n;++i)
#pragma GCC optimize(1)
#pragma G++ optimize(1)
#pragma GCC optimize(2)
#pragma G++ optimize(2)
#pragma GCC optimize(3)
#pragma G++ optimize(3)
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#define pii pair<int,int>
#pragma GCC diagnostic error "-std=c++11"
using namespace std;
inline void rdl(long long &val){
    long long x=0;
    int f=1;
    char ch=getchar();
    while((ch<'0' or ch>'9') and ch!='-') ch=getchar();
    if(ch=='-'){
        f=-1;
        ch=getchar();
	}
	while(ch>='0' and ch<='9'){
	    x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
    val=x*f;
}
inline void rdi(int &val){
    int x=0;
    int f=1;
    char ch=getchar();
    while((ch<'0' or ch>'9') and ch!='-') ch=getchar();
    if(ch=='-'){
        f=-1;
        ch=getchar();
    }
    while(ch>='0' and ch<='9'){
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    val=x*f;
}
inline long long rdl(){
    long long x=0;
    int f=1;
    char ch=getchar();
    while((ch<'0' or ch>'9') and ch!='-') ch=getchar();
    if(ch=='-'){
        f=-1;
        ch=getchar();
    }
    while(ch>='0' and ch<='9'){
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return x*f;
}
inline int rdi(){
    int x=0;
    int f=1;
	char ch=getchar();
	while((ch<'0' or ch>'9') and ch!='-') ch=getchar();
	if(ch=='-'){
        f=-1;
        ch=getchar();
    }
    while(ch>='0' and ch<='9'){
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return x*f;
}
inline void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
inline void _write(int x){
	write(x);
	putchar(' ');
}
inline void print(int x){
	write(x);
	putchar('\n');
}
inline void write(ll x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
inline void _write(ll x){
	write(x);
	putchar(' ');
}
inline void print(ll x){
	write(x);
	putchar('\n');
}
const ll md=1000000007;
inline ll qp(ll a,ll b){
	ll rt=1;
	while(b){
		if(b&1) rt=(rt*a)%md;
		a=(a*a)%md;
		b>>=1; 
	}
	return rt;
}
ll w[111],dp[111];
int n;
int main(){
	int i,j,k;
	rdi(n);
	for(i=1;i<=n;++i) rdl(w[i]);
	dp[0]=1;
	w[n+1]=1;
	for(i=1;i<n+2;++i){
		dp[i]=dp[i-1]*2%md;
		for(j=1;j<i;++j){
			ll t=max(w[i],w[j-1]),mn=w[j]-1;
			ll sum=0;
			for(k=j;k<i;++k) mn=min(mn,w[k]-1),sum+=max(w[k+1]-w[k],0ll);
			if(t<=mn){
				ll t1=qp(2,w[j]-1-mn);
				ll t2=qp(2,mn-t+1)-1;
				ll t3=qp(2,sum);
				dp[i]=(dp[i]+4ll*dp[j-1]*t1%md*t2%md*t3)%md;
			}
		}
	}
	print(dp[n+1]*500000004ll%md);
}