#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define MOD 1000000007

using namespace std;

void init(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

// code from below

ll dp[3001][3001];
void solve(){
	ll n;
    cin>>n;
    vector<ll> arr(n);
    FOR(i,n)
        cin>>arr[i];
    // dp[i][j] stores the x-y value if both players play optimally, considering subarr from i to j of arr
    // thus we have n^2 sub array thus dp is of n^2 size
    for(int L=n-1;L>=0;L--){
        for(int R=L;R<n;R++){
            if(L==R)
                dp[L][R]=arr[R];
            else{
                dp[L][R]=max(arr[L]-dp[L+1][R],arr[R]-dp[L][R-1]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
}

int main(){
    int t=1;
    //cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}