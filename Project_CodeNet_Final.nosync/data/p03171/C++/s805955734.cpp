#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for( int i=a; i<b; i++)
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef vector<pii>vpi;
vector<vvll> dp(3001,vvll(3001,vll(2)));
ll solve(ll L,ll R,bool turn,ll diff,vll &A){
    ll n = A.size();
    for(ll i=0;i<n;i++){
        dp[i][i][0] = A[i];
        dp[i][i][1] = -A[i];
    }
    ll delta = 1;
    ll x,y;
    while(delta < n){
        x = 0;
        y = delta;
        while(y<n){
            dp[x][y][0] = max(dp[x+1][y][1]+A[x],dp[x][y-1][1]+A[y]);
            dp[x][y][1] = min(dp[x+1][y][0]-A[x],dp[x][y-1][0]-A[y]);
            x++;y++;
        }
        delta++;
    }
    // for(ll i =0;i<n;i++){
    //     for(ll j =0;j<n;j++){
    //         if(j<i){
    //             cout<<"\t ";
    //         }
    //         else{
    //             cout<<"("<<dp[i][j][0]<<","<<dp[i][j][1]<<") ";
    //         }
    //     }
    //     cout<<"\n";
    // }
    return dp[L][R][turn];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n;
    cin>>n;
    vll A(n);
    for(ll i =0;i<n;i++){
        cin>>A[i];
    }
    cout<<solve(0,n-1,0,0,A)<<"\n";
}