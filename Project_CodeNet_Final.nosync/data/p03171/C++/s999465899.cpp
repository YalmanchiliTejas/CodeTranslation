#include<iostream>
#include<bits/stdc++.h>
#include<climits>
#include<math.h>

#define forn(e,n,s) for(int i = e; i < n;i += s)
#define forr(e,n,s) for(int i = e; i >= n; i -= s)
#define PI 3.14159265358979323846264338327950L
#define ll long long

using namespace std;

const int MOD = 1e9+7;

void go(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout<<fixed;
  cout<<setprecision(20);

  #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
  #endif
}
int main(){
    go(); 

    // code here
    int n;cin>>n;
    ll arr[n];
    forn(0,n,1) cin>>arr[i];
    vector<vector<ll>> dp(n,vector<ll>(n,0));
    for(int i = n-1; i >= 0; i--){
        for(int j = i; j < n; j++){
            if(i==j){
                dp[i][j] = arr[i];
            }else{
                dp[i][j] = max(arr[i] - dp[i+1][j], arr[j] - dp[i][j-1]);
            }
        }
    }
    cout<<dp[0][n-1];
  
}







