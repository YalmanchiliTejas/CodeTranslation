#include<bits/stdc++.h>
using namespace std;
#define int 		  long long
#define	pb 			  push_back
#define all(a)		  (a).begin(),(a).end()
#define sz(x)		  (int)x.size()
#define endl	 	  "\n"
#define inf 		  1000000007
#define FOR(i, a, b)  for(int i=a; i<b; i++)

mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count()); 
#define SHUF(v) shuffle(all(v), RNG);
// Use mt19937_64 for 64 bit random numbers. 

//int dp[333][2];

void solve(){
	int n, m;
	cin>>n>>m;
	n==m?(cout<<"Yes"):(cout<<"No");
}	

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	//cin>>t;
	FOR(i, 1, t+1){	
	//	cout<<"Case #"<<i<<":"<<endl;
		solve();
	}
	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
 
}