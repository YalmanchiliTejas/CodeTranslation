#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long int
#define pb push_back
#define mp make_pair
#define ip pair<int, int>
#define it pair<int, pair<int, int>>
#define F first
#define S second
#define fori(p, n) for(int i = p; i < n; i++)
#define forj(q, m) for(int j = q; j < m; j++)
#define fork(r, l) for(int k = r; k < l; k++)
#define revi(h) for(int i = h; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define PI 3.14159265358
#define debug(x) cout<<"DEBUGGING --- "<<x<<endl;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define input_from_file  freopen("input.txt", "r", stdin);
#define output_to_file freopen("output.txt", "w", stdout);
vector<int>A(3005);
vector<vector<int>>dp(3005, vector<int>(3005, 0));
int solve(int l, int r){
    if(dp[l][r] != 0) return dp[l][r];
    if(l == r) return dp[l][r] = A[l];
    if(l > r) return 0;
    return dp[l][r] = max(A[l] - solve(l + 1, r), A[r] - solve(l, r - 1));    
}
signed main(){
    fastio;
    //input_from_file; 
    //output_to_file;
    int n; cin>>n;
    fori(0, n) cin>>A[i];
    cout<<solve(0, n - 1)<<endl;
}