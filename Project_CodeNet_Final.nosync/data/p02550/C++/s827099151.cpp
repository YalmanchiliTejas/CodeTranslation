
// Problem : E - Sequence Sum
// Contest : AtCoder - AtCoder Beginner Contest 179
// URL : https://atcoder.jp/contests/abc179/tasks/abc179_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args&&... args) {
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#define int long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MOD 1000000007
#define mod 998244353
#define bug cout<<"HY"<<endl
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define numize(A) A.numize(unique(A.begin(), A.end()) - A.begin())
typedef pair<int,int> P;
int power(int a,int b)
{
    if(b==0)
        return 1;
    if(b%2==0)
        return (power((a*a)%mod,b/2))%mod;
    return (a*(power((a*a)%mod,b/2))%mod)%mod;
}
int modInv(int n)
{
    return power(n, MOD-2);
}
int nCr(int n, int r, int p=MOD)
{
   if (r==0)
      return 1;
    int Fact[n+1];
    Fact[0] = 1;
    for (int i=1 ; i<=n; i++)
    {
        Fact[i] = (Fact[i-1]*i)%p;
    }
    return (((Fact[n]* modInv(Fact[r])) % MOD) *(modInv(Fact[n-r]) % MOD)) % MOD;
}
double PI=3.14159265359;
void solve()
{
	int n,x,m,i;
	cin>>n>>x>>m;
	int Cnt[m];
	int V[m];
	memset(Cnt,0,sizeof(Cnt));
	memset(V,0,sizeof(V));
	while(n && x)
	{
		if(Cnt[x]>0)
			break;
		V[x]=(x*x)%m;
		Cnt[x]++;
		x=(x*x)%m;
		n--;
	}
	if(n!=0 && x!=0)
	{
		int num=1;
		int s=x;
		int cycle=1;
		while(V[s]!=x)
		{
			cycle++;
			s=V[s];
		}
		int time=n/cycle;
		int extra=n%cycle;
		// cout<<x<<" "<<time<<" "<<extra<<" "<<<n<<" "<<cycle<<endl;
		// return;
		while(n>0)
		{
			Cnt[x]+=time+(extra?1:0);
			n-=(time+(extra?1:0));
			x=(x*x)%m;
			if(extra>0)
				extra--;
		}
	}
	int ans=0;
	for(i=0;i<m;i++)
	{
		ans+=i*Cnt[i];
	}
	cout<<ans<<endl;
}
int32_t main()
{
    boost;
    int  t=1;
    // cin>>t;
    while(t--)
    {
    	solve();
    }
}
