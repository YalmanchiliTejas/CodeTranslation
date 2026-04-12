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
    for(int l = n - 1; l >= 0; --l){
        for(int r = l; r < n; ++r){
            if(l == r){
                dp[l][r] = a[l];
            }else{
                dp[l][r] = max(a[l] - dp[l+1][r],a[r] - dp[l][r - 1]);
            }
        }
    }
    // cout << dp[0][n-1];
    cout << dp[0][n-1];
}