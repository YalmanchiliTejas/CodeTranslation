#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount

template<typename T1,typename T2>
std::istream& operator>>(std::istream& in,pair<T1,T2> &a)
{
	in>>a.fr>>a.sc;
	return in;
}
template<typename T1,typename T2>
std::ostream& operator<<(std::ostream& out,pair<T1,T2> &a)
{
	out<<a.fr<<" "<<a.sc;
	return out;
}

int n;
int a[3005];
int dp[3005][3005];
int calc(int l,int u,int m){
	if(l==u){
		return (1-m)*a[l];
	}
	int &ans=dp[l][u];
	if(ans!=-1)return ans;
	if(m){
		ans=min(calc(l+1,u,!m),calc(l,u-1,!m));
	}
	else{
		ans=max(a[l]+calc(l+1,u,!m),a[u]+calc(l,u-1,!m));
	}
	return ans;
}
void solve(){
	mem1(dp);
	cin>>n;
	int s=0;
	rep(i,0,n)cin>>a[i],s+=a[i];
	int x=calc(0,n-1,0),y=s-x;
	cout<<x-y;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	#ifdef DSU
		cleardsu(MAXDSUSIZE);
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}
