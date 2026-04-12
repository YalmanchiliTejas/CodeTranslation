#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forit(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define REP(i,f,t) for(int i=f;i<(int)t;++i)
#define pb push_back
#define mp make_pair
#define all(a) begin(a),end(a)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int inf = 1e9+5;

int n,k,i,j;
int main(){
	fast_io;
	cin >> n;
	vector<vector<ll>> dp(n,vector<ll>(n));
	vector<ll> a(n);
	for(ll &x : a)cin>>x;
	for(int L = n - 1; L>=0;--L){
        for(int R = L; R<n;++R){
            if(L==R)dp[L][R]=a[L];
            else{
                dp[L][R] = max(a[L] - dp[L+1][R], a[R] - dp[L][R-1]);
            }
        }
	}
	cout << dp[0][n-1];
}
