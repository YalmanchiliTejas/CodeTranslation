#include <bits/stdc++.h>
#define MOD  1000000007

using namespace std;
typedef long long int lli;
typedef long double ld;
lli ar[3001];
lli dp[3001][3001];

lli power(lli a, lli b){
    if(b==0){
        return 1;
    }
    if(b&1){
        return a*power(a*a,b/2);
    }
    return power(a*a,b/2);
}

lli recu(int i, int j){
    if(i>j){
        return 0;
    }
    if(dp[i][j] != -1){
        //cout<<i<<" "<<j<<endl;
        return dp[i][j];
    }
    lli x=((i+2)<=j)?recu(i+2,j):0;
    lli y=((i+1)<=(j-1))?recu(i+1, j-1):0;
    lli z=(i<=(j-2))?recu(i, j-2):0;
    dp[i][j]=max(ar[i]+min(x, y), ar[j]+min(y, z));
    //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    return dp[i][j];
}

void solve(){
    lli n;
    cin>>n;
    lli sum=0;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++){
        cin>>ar[i];
        sum+=ar[i];
    }
    lli x;
    x=recu(0, n-1);
    lli y=sum-x;
    //cout<<x<<" "<<y<<endl;
    cout<<x-y<<endl;
}

signed main(){
    /*#ifndef ONLINE_JUDGE
    //for getting input from input.txt
    freopen("input.txt", "r", stdin);
    //for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
