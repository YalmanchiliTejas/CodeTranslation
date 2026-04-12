
// Problem : C - Sum of product of pairs
// Contest : AtCoder - AtCoder Beginner Contest 177
// URL : https://atcoder.jp/contests/abc177/tasks/abc177_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
#define 	ll		    long long
#define 	rep(i,a,n)  for(int i=a;i<n;i++)
#define 	MOD 		1000000007
#define 	vp 			vector<pair<int,int> >
#define 	ff 			first
#define 	ss 			second
#define 	pb 			push_back
#define 	all(x) 		(x).begin(),(x).end()
#define 	dg(x)		cerr<<"--- x = "<<x<<"\n"
#define 	endl		"\n"


using namespace std;
const int N = 2e5  + 5;
ll ar[N];
ll cfreq[N];

ll mod_expo(ll a, ll b){
	
	ll ans = 1;
	while(b){
		if(b & 1)
			ans = ans * a % MOD;
		b = b >> 1;
		a = a * a % MOD;
	}
	return ans ;
}

void solve(){
	int n; cin >> n;
	
	int ans = 0;
	cfreq[n + 1] = 0;
	
	rep(i ,1 ,n + 1)
		cin >> ar[i];
	
	for(int i = n; i >= 1; i--)
		cfreq[i] = (cfreq[i + 1] + ar[i]) % MOD;
	
	rep(i, 1, n)
		ans = (ans + (cfreq[i + 1] * ar[i]) % MOD)  % MOD;	
	
	cout << ans << endl;
	
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
}
