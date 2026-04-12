#include<bits/stdc++.h>


using namespace std;

#define int long long
#define all(a) a.begin(),a.end()
#define sz(x) ((int)x.size())
#define ff first 
#define ss second 
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vpii;
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    vi a(n);
    cin >> a;
    vvi dp(n,vi(n));
    for(int gap = 0; gap < n; ++gap){
        for(int i = 0; i < n; ++i){
            int l = i, r = i + gap;
            if(r < n){
                if(l == r){
                    dp[l][r] = a[l];
                }else if(l + 1 == r){
                    dp[l][r] = max(a[l],a[r]);
                }else {
                    dp[l][r] = max(a[l] + min(dp[l+2][r],dp[l + 1][r - 1]),a[r] + min(dp[l+1][r-1],dp[l][r-2]));
                }
            }
        }
    }
    // cout << dp[0][n-1];
    int x = accumulate(all(a),0LL);
    cout << 2*dp[0][n-1] - x;
}