#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<string>
#define ls k<<1,l,mid
#define rs k<<1|1,mid+1,r
#define mp(x,y) make_pair(x,y)
#define r(x) read(x)
#define rr(x,y) read(x);read(y)
#define rrr(x,y,z) read(x);read(y);read(z)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define pb(x) push_back(x)
#define sss(str) scanf("%s",str+1)
#define ssf(x) scanf("%lf",&x)
#define aLL(x) x.begin(),x.end()
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef double dd;
typedef pair<int,int> pt;
const int N=2e5+5;
const int M=2e3+50;
const int INF=0x7fffffff;
const int mod=1e9+7;
const int sz=18;
const double eps=1e-10;
const double pi=acos(-1);
//***********************
int n,m;
char str[M];
int f[N];
//***********************
template<class T>
inline void read(T &x)
{
    char c; x=1;
    while((c=getchar())<'0'||c>'9') if(c=='-') x=-1;
    T res=c-'0';
    while((c=getchar())>='0'&&c<='9') res=res*10+c-'0';
    x*=res;
}
int main()
{
    sss(str);
    bool f1=0,f2=0;
    FOR(i,1,3){
        if(str[i]=='A') f1=1;
        else if(str[i]=='B') f2=1;
    }
    if(f1&&f2) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
