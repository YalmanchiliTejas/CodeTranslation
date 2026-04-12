#include<bits/stdc++.h>
using namespace std;
#define int           long long
#define	pb            push_back
#define all(a)        (a).begin(),(a).end()
#define sz(x)         (int)x.size()
#define F             first
#define S             second
#define endl          "\n"
#define inf           1000000007
#define FOR(i, a, b)  for(int i=a; i<b; i++)
#define bigboi        1e18
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count()); 
#define SHUF(v) shuffle(all(v), RNG);
// Use mt19937_64 for 64 bit random numbers. 


void solve(){
	string s;
	cin>>s;
	int cnt=0;
	FOR(i, 0, sz(s)) if(s[i]=='A') cnt++;
	if(cnt==0 || cnt==3) cout<<"No";
	else cout<<"Yes";	
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
