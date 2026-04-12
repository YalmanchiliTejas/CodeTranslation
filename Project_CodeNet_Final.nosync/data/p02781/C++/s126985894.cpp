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
vi a;
ll dp[103][4][2];

ll func(int x, int k, int m){
	if(k<0){
		return 0;
	}

	if(x==a.size()){
		if(!k){
			return 1;
		}
		else{
			return 0;
		}
	}
	
	if(dp[x][k][m]!=-1){
		return dp[x][k][m];
	}
	ll ans = 0;
	if(m==1){
		for(int i=0;i<10;i++){
		    ans+=func(x+1,k-(i!=0),1);
		}
	}
	else{
		for(int i=0;i<=a[x];i++){
		    ans+=func(x+1,k-(i!=0),(i!=a[x]));
		}
	}
	return dp[x][k][m] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,x,t,m,k;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		a.pb(s[i]-'0');
	}
	MSET(dp,-1);
	cin>>k;
	cout<<func(0,k,0);
	return 0;
}




