#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
ld EPS = 1e-12;
int INF = numeric_limits<int>::max() / 2;
int MOD = 1e9 + 7;
#define rep(i,n) for(int i = 0; i < n; i++)
#define all(obj) (obj).begin(), (obj).end()
#define debug(x) cerr << #x << ": " << x << '\n'

map<pair<int,ll>,ll> dp;
ll num[60];
 
ll rec(int n,ll k){
    if(k==0)return 0;
    if(n==0)return k==1;
    if(dp[make_pair(n,k)])return dp[make_pair(n,k)];
    ll ret=0;
    ret+=rec(n-1,min(k-1,num[n-1]));
    if(k>=num[n-1]+2){
        ++ret;
        ret+=rec(n-1,min(num[n-1],k-num[n-1]-2));
    }
    return dp[make_pair(n,k)]=ret;
}
 
int main(){
    ll n,k;
    cin>>n>>k;
    num[0]=1;
    rep(i,50)num[i+1]=2*num[i]+3;
    cout<<rec(n,k)<<endl;
    return 0;
}