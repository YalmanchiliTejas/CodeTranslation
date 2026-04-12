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
int a[10005];
int d;
int dp[10005][105][2];

int calc(int p,int s,int f){
	if(p==n)return s==0;
	int &ans=dp[p][s][f];
	if(ans!=-1)return ans;
	ans=0;
	if(!f){
		rep(i,0,a[p]){
			ans+=calc(p+1,(s+i)%d,1);
			ans%=M;
		}
		ans+=calc(p+1,(s+a[p])%d,0);
		ans%=M;
	}
	else{
		rep(i,0,10){
			ans+=calc(p+1,(s+i)%d,1);
			ans%=M;
		}
	}
	// cout<<p<<" "<<s<<" "<<f<<" "<<ans<<"\n";
	return ans;
}
void solve(){
	mem1(dp);
	string s;
	cin>>s>>d;
	n=sz(s);
	rep(i,0,n){
		a[i]=s[i]-'0';
	}
	cout<<(calc(0,0,0)+M-1)%M;
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
