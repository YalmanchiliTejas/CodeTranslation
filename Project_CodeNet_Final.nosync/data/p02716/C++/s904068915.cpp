#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LLMAX (1ll << 60) - 1
#define INTMAX (1 << 30) - 1
#define MOD 1000000007 
#define NMAX 1000*100+1

#define numberOfSetBits(S) __builtin_popcount(S) // __builtin_popcountl(S) __builtin_popcountll(S)
#define MSET(x,y) memset(x,y,sizeof(x))
#define gcd(a,b) __gcd(a,b)
#define all(x)  x.begin(),x.end()
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define print(x)    for(auto it=x.begin();it!=x.end();it++) cout<<*it<<' '; cout<<endl;
#define printii(x)  for(auto it=x.begin();it!=x.end();it++) cout<<*it.F<<' '<<*it.S<<'\t';  cout<<endl;
#define in(x,n)   for(int e=0;e<n;e++){ll y;cin>>y;x.pb(y);}

#define vi vector<ll>
#define vvi vector<vi>
#define ii pair<ll,ll>
#define pll pair<ll,ll>
#define vii vector<ii>
#define viii vector<pair<ii,ll>>
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define mc(a,b,c) mp(mp(a,b),c)


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,x,t,m;
	cin>>n;
	vi a(n+1),dp(n+1),pref(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0] = 0;
	dp[1] = 0;
	pref[1] = a[1];
	for(int i=3;i<=n;i+=2){
	    pref[i] = a[i]+pref[i-2];
	}
	for(int i=2;i<=n;i++){
	    if(i&1){
	    	dp[i] = max(dp[i-2]+a[i], dp[i-1]);
	    }
	    else{
	    	dp[i] = max(dp[i-2]+a[i], pref[i-1]);
	    }
	}

	cout<<dp[n];
	
	

	return 0;
}





