#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<complex>
#include<iomanip>
#include<unordered_map>
#define deg(x) cerr<<#x<<"="<<x<<endl;
#define fd(x) for(int i=0;i<x;i++)
#define fdd(a,x) for(int i=a;i<x;i++)
#define fx(x,n) for(int i=n-1;i>=x;i--)
#define mst(x) memset(x,0,sizeof(x));
#define fi first
#define se second
#define TB ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ok "ok"
#define HH puts("");
#define ls rt<<1
#define rs rt<<1|1
#define pb(a,b) a.push_back(b);
#define FIN  freopen("1.in","r",stdin);
#define FOUT freopen("1.out","w",stdout);
using namespace std;
typedef long long ll;typedef long long LL;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<string,int> pss;
typedef unsigned long long ull;
const ll mod=1e9+7;
const int inf=1e9+7;
const double eps=1e-6;
ll qpow(ll a,ll b,ll m){ ll r=1;a%=m;for(;b;b>>=1){if(b&1)r=r*a%m;a=a*a%m;}return (r+m)%m;}
const double pi=acos(-1);

int main(){
	int x;cin>>x;
	if(x>=30)puts("Yes");
	else puts("No");
}
