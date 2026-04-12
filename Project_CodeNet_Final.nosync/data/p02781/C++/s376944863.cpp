#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define pb push_back
#define fi first
#define se second
#define ld long double
#define vi vector<vector<ll> >
using namespace std;
const int MOD=1000000007;
const int MOD2=15000007;
const ll MAX=9187201950435737471;
const int N=100005;
const int INF=1e17;
const long double PI=acos(-1);

string s;
int k,n;

ll dp[102][2][4];

ll f(int idx,bool c,int num){
    if(idx==n){
        if(num==k){
            //cout<<num<<"\n";
            return 1;
        }
        return 0;
    }
    if(num==k){
        return 1;
    }
    int d=9;
    ll &ret=dp[idx][c][num];
    if(ret!=-1){
        return ret;
    }
    ret=0;
    if(c){
        d=s[idx]-'0';
    }
    for(int i=0;i<=d;i++){
        bool new_c=(c && i==s[idx]-'0');
        ret+=(i>0)?f(idx+1,new_c,num+1):f(idx+1,new_c,num);
    }
    return ret;
}

void solve(int T){
    memset(dp,-1,sizeof dp);
    cin>>s>>k;
    n=s.size();
    cout<<f(0,1,0);
}

int main() {
    fastio
    int T=1;
    //cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
        //if(i<T)cout<<"\n";
    }
    return 0;
}



