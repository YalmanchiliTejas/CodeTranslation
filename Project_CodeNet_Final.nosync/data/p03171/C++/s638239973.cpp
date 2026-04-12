#include <bits/stdc++.h>
using namespace std;
#define ll long long 
long long int dp[3001][3001];

vector<ll> v;

ll solve( int i, int j){


if(dp[i][j]!=-1){
    return dp[i][j];

}
if(i>j){
   return 0;

}

if(i==j){
    return v[i];
}

if(j==i+1){
    return max(v[i],v[j]);

}


long long int ans=max(v[i]+min(solve(i+2,j),solve(i+1,j-1)), v[j]+min(solve(i+1,j-1),solve(i,j-2)));

return dp[i][j]=ans;


}


int main() {
    int n;
    cin>>n;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;

        }
    }

    

     ll totalsum=0;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        totalsum+=x;

        v.push_back(x);

    }

    ll X=solve(0,v.size()-1);

    

    ll Y=totalsum-X;

    cout<<X-Y;



   

}
