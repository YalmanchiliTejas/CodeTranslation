#include<bits/stdc++.h>
using namespace std;
#define eps 1e-9
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Fore(i,a,b) for(int i=a;i>=b;i--)
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define mkp make_pair
#define pb push_back
#define siz size()
#define met(a,b) memset(a,b,sizeof(a))
#define iossy ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define fr freopen
#define pi acos(-1.0)
#define Vector Point
#define fir first
#define sec second
#define endl '\n'
typedef pair<int,int> pii;
typedef unsigned long long ull;
const long long linf=1LL<<62;
const int iinf=1000000009;
const double dinf=1e15;
const int Mod=1e9+9;
const int base=228;
typedef long long ll;
typedef long double ld;
struct Solver {
	ll cnt=1,crt=1;
	ll n,k;
	ll len[55],num[55];
	void cal(int x) {
		len[x]=cnt;num[x]=crt;
		cnt=cnt*2+3;crt=crt*2+1;
		if(x==n) return ;
		cal(x+1);
	}
	ll dfs(int x,ll xx) {
		ll res=0;
		if(xx==0) return 0;
		if(x==0) return 1;
		if(len[x]<=xx) return num[x];
		if(xx<=len[x]/2) return dfs(x-1,xx-1);
		if(xx==len[x]/2+1) return num[x]/2+1;
		if(xx>len[x]/2+1) return num[x]/2+1+dfs(x-1,xx-len[x]/2-1);
	}
	void solve(){
		iossy;
		cin>>n>>k;cnt=1;
		cal(0);
		cout<<dfs(n,k)<<endl;
	}
};
int main(){
//	p[0]=1;
//	For(i,1,500005) p[i]=p[i-1]*base;
//	while(scanf("%d",&n)!=EOF) solve();
	int t=1;
	Solver solver;
	solver.solve();
	return 0;
}
