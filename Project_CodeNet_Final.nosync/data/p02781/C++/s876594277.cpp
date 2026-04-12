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

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
template<typename T1,typename T2>std::istream& operator>>(std::istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>std::ostream& operator<<(std::ostream& out,pair<T1,T2> &a){out<<a.fr<<" "<<a.sc;return out;}

const int N=0;
int a[200],k,s;

int dp[200][4][2];

int calc(int i,int k,int f){
	if(k==0)return 1;
	if(i==s)return 0;
	int &ans=dp[i][k][f];
	if(ans!=-1)return ans;
	ans=0;
	if(f){
		ans+=calc(i+1,k,f);
		ans+=9*calc(i+1,k-1,f);
	}
	else{
		if(a[i]==0)ans=calc(i+1,k,0);
		else{
			ans+=calc(i+1,k,1);
			ans+=(a[i]-1)*calc(i+1,k-1,1);
			ans+=calc(i+1,k-1,0);
		}
	}
	return ans;
}

void solve(){
	mem1(dp);
	string n;
	cin>>n>>k;
	s=sz(n);
	rep(i,0,s){
		a[i]=n[i]-'0';
	}
	cout<<calc(0,k,0);
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
