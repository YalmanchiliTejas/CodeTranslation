/* _________________________________________________________________________________________________
  |                                                                                                 |
  |                             Author      : Aditya Ahuja                                          |
  |                             Date        : Thu, 20th Jun 2019                                    |
  |_________________________________________________________________________________________________|
*/
 
#include<bits/stdc++.h>
using namespace std;

// #define int long long

#define pb          push_back
#define F           first
#define S           second
#define rep(i,a,b)  for(int i=a; i<b; i++)
#define all(a)      (a).begin(),(a).end()
#define ret(x)      {cout << (x) << endl; return;}
#define sz(x)       (int)x.size()
#define type(x)     typeid(x).name()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<vector<int>> vii;

#define wa(x)       cout << (#x) << " -------- " << (x) << endl
#define pvi(v)      {for(auto it:v) cout << it << " "; cout << endl;}
#define line1	    printf("---------------------------\n")

// #define wa //
// #define line1 //
// #define pvi //
// #define printf //

void solve();
signed main() {
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	////cout << fixed << setprecision(10);

	int t=1; 
	//cin>>t;
	while(t--) solve();
	return 0;
}

//___________________________________________________________________________________________________

const int nax = 3005;
ll dp[nax][nax];

void solve() {

	int n;
	cin >> n;

	vi a(n);
	rep(i,0,n) cin >> a[i];

	for(int l=n-1; l>=0; --l){
		for(int r=l; r<n; ++r){
			if(l==r) dp[l][r] = a[l];
			else dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
		}
	}

	ret(dp[0][n-1]);
}
