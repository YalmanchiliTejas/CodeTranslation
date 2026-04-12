#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> Pl;
#define all(a) (a).begin(),(a).end()
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(ll i=(a);i<(b);i++)
#define rrep(i,n) for(ll (i)=(n)-1;(i)>=0;i--)
#define SHOW(x) cout << #x << ": " << x << endl;
const ll INF=1e18,MOD = 1e9+7;
const int iINF = 1e9;

int main(){
    ll count,dp[101/*桁数*/][5/*0ではないものの個数(0,1,2,3)*/][2/*smaller*/],digit;
    string n;
    cin>>n>>count;
    rep(i,101)rep(j,5)rep(k,2)dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    digit = n.size();
    rep(i,digit){
        int num = n[i] - '0';
        rep(j,count + 1)rep(k,2)rep(d,(k)?10:num + 1){
            dp[i + 1][j + (d != 0)][k || d < num] += dp[i][j][k];
        }  
    }
    cout<<dp[digit][count][0] + dp[digit][count][1]<<endl;
}