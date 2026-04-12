#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define pb push_back
#define fi first
#define se second
#define Mod 1000000007


int main(){
    ll i,j;
    ll n;
    cin>>n;

    ll a[n];
    for(i=0;i<n;i++) cin>>a[i];

    ll dp[n][n];

    for(i=0;i<n;i++){
        dp[i][i]=a[i];
    }
    for(j=1;j<n;j++){
        for(i=0;i+j<n;i++){
            dp[i][i+j]=max(a[i]-dp[i+1][i+j],a[i+j]-dp[i][i+j-1]);
        }

    }

    cout<<dp[0][n-1]<<endl;

}
