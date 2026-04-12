#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[3001][3001];

ll dequeGame(const vector<ll>& v,int s,int e) {
    if(s>e){
        return 0;
    }

    if(dp[s][e]!=-1) {
        return dp[s][e];
    }


    ll option1 = v[s] + min(dequeGame(v,s+2,e),dequeGame(v,s+1,e-1));
    ll option2 = v[e] + min(dequeGame(v,s,e-2),dequeGame(v,s+1,e-1));

    return dp[s][e] = max(option1, option2);
}


int main() {
    int n;
    cin>>n;

    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }

    memset(dp,-1,sizeof dp);

    ll playerOneScore = dequeGame(v,0,n-1);
    ll playerTwoScore = accumulate(v.begin(), v.end(), (ll)0) - playerOneScore;
    cout  << playerOneScore - playerTwoScore << "\n";

    return 0;
}