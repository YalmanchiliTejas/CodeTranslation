#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll dp[3001][3001];
int main(){
    int n,A[30001];
    cin>>n;
    rep(i,n) cin>>A[i];
    fill(dp[0],dp[0]+n+1,0);
    rep(i,n){
        rep(j,n-i){
            dp[i+1][j]=max(A[j+i]-dp[i][j],A[j]-dp[i][j+1]);
        }
    }
    cout<<dp[n][0]<<"\n";
}