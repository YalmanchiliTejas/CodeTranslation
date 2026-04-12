#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod=1e9+7;
ll a[3000];
ll dp[3000][3000];
void f(int st, int end){
    if(st==end){
        dp[st][st]=a[st]; return ;
    }
    if(dp[st+1][end]==-1) f(st+1,end);
    if(dp[st][end-1]==-1) f(st,end-1);
    dp[st][end]=max(a[st]-dp[st+1][end],a[end]-dp[st][end-1]);
}
int main() {
    /*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<3000;i++){
        for(int j=0;j<3000;j++){
            dp[i][j]=-1;
        }
    }
    f(0,n-1);
    cout<<dp[0][n-1];
}