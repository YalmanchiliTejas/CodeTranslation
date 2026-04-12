#include<stdio.h> 
#include<iostream> 
#include<string.h>
#include<cstring>
#include<string>
#include<math.h>
#include<algorithm>
#include<bits/stdc++.h>
#include<map>
#include<vector>
#include<cmath>
#include<queue>
#include<set>
#define cuttime ios::sync_with_stdio(false)
#define swap(x, y) x ^= y, y ^= x, x^= y
#define INF 0x3f3f3f3f
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define dep(i,a,b) for(int i=(a);i>=(b);--i)
#define scan1(x) scanf("%d",&x)
#define scan2(x,y) scanf("%d%d",&x,&y)
#define scan3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define scanll1(x) scanf("%lld",&x)
#define scanll2(x,y) scanf("%lld%lld",&x,&y)
#define scanll3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define lowbit(x) (x&(-x))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define debug(x) cout <<#x<<": "<<x<<endl
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int N=5e6+20;
const int mod=1e9+7;
inline ll read() {
    char c=getchar();ll x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0',c=getchar();}
    return x*f;
}
inline void out(ll x) {   
    if(x>9) out(x/10);   
    putchar(x%10+'0'); 
}

int main(){
    int x=read();
    if(x>=30)puts("Yes");
    else puts("No");
}
/*
 */