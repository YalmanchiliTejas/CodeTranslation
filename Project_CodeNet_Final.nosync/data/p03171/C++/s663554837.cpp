#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=3001;
ll n,a[maxn],memo[maxn][maxn][2];

ll go(ll i,ll j,ll par){
    if(i>j){
        return 0;
    }
    ll ans=0;
    if(memo[i][j][par]!=-1) return memo[i][j][par];
    if(par==0){
        ans+=max(a[i]+go(i+1,j,!par),a[j]+go(i,j-1,!par));
    }
    else{
        ans+=min(go(i+1,j,!par)-a[i],go(i,j-1,!par)-a[j]);
    }
    return memo[i][j][par]=ans;
}


int main(){
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    memset(memo,-1,sizeof(memo));
    cout<<go(0,n-1,0);
}