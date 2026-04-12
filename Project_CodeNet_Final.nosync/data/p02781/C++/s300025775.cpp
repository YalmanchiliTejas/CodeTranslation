#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
*this << "[";
for (auto it = d.b; it != d.e; ++it)
*this << ", " + 2 * (it == d.b) << *it;
ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define cool ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int  long long int
#define pb push_back
#define fe first
#define lb lower_bound 
#define ub upper_bound
#define pii pair<pair<int,int>,pair<int,int> >
#define se second
#define endl "\n"
#define pi pair<int, int>
#define mi          map<int,int>
#define mii         map<pi,int>
#define vi vector<int> 
#define vvi vector<vi>
#define bs   binary_search
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,a,b) for(int i=a;i<=b;i++)	
#define all(c) (c).begin(),(c).end()
#define sz(x)       (int)x.size() 
#define PI 3.14159265358979323846

 const int N=1e2+5;

 int mod= 1e9+7;
 int dx[4]={0,0,+1,-1};
 int dy[4]={+1,-1,0,0};  
 
 
int po(int a, int b) {
	a %= mod;
	int res = 1;
	while (b > 0) {
		if (b & 1)
			res = (res * a) % mod;
		a =(a*a) % mod;
		b >>= 1;
	}
	 return res;	
  }


string s;
int k,dp[N][N][2];
vi nax;



int cal(int pos,int cnt,int f) {
	  if(pos==sz(nax)) {
		    if(cnt==k) return 1;
		    else return 0;
		  }
	  
	  if(dp[pos][cnt][f]!=-1) return dp[pos][cnt][f];
	  
	  int yan=(f?9:nax[pos]);
	  int ans=0;
	  for(int i=0;i<=yan;i++) {
		     int ct=cnt;
		     int cf=f;
		     if(i<nax[pos]) cf=1;
		     if(i!=0) ct++;
		     ans+=cal(pos+1,ct,cf);
		  }	   
		  
		  return dp[pos][cnt][f]=ans;
}

void solve() {
   cin>>s;
   cin>>k;
   
   memset(dp,-1,sizeof(dp));
   
   rep(i,0,sz(s)) {
	      int yo=s[i]-'0';
	      nax.pb(yo);
	   }
   
   int res=0;
   res+=cal(0,0,0);
   cout<<res<<endl;     
               
}

    
int32_t main() {
	cool;
	int t=1;	

	//cin>>t;
	while(t--)
	  solve();

  return 0;	   
}
