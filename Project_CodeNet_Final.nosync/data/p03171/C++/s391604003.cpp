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

int n;
vi a;
vvi dp;
int solve(int l, int r){
    if(r == l + 1){
        return max(a[l],a[r]);
    }
    if(l == r)return a[l];

    if(dp[l][r] != -1) return dp[l][r];

    dp[l][r] = max(a[l] + min(solve(l + 2,r),solve(l + 1,r - 1)), a[r] + min(solve(l + 1, r - 1),solve(l,r - 2)));

    return dp[l][r];
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    dp.resize(n + 1,vi(n + 1,-1));
    cin >> a;
    int x = solve(0,n - 1);
    int y = accumulate(all(a),0LL);
    cout << 2*x - y;
}