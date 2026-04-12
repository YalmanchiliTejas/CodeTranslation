#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define ob pop_back
#define xx first
#define yy second
#define dob double
#define int long long int
#define ss size()
using namespace std;
const int M=1e9+7,maxn=3005;
std::vector<int> adj[30];
std::vector<int> v1;
std::vector<int> v;
int ans,n,k,m,x,y,q,par[maxn],h[maxn],mach[maxn],sk[maxn],dp[maxn][maxn];
bool mark[maxn];
int32_t main(){
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        dp[i][1]=a[i];
    }
    for(int j=2;j<=n;j++){
        for(int i=0;i<=n-j;i++){
            dp[i][j]=max(a[i]-dp[i+1][j-1],a[i+j-1]-dp[i][j-1]);
        }
    }
    cout<<dp[0][n];
    return 0;
}
