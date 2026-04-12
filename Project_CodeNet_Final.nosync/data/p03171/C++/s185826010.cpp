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
const ll MAX=9187201950435737471;
const int N=100005;
const ll INF=-1e12;
const double pi=acos(-1);

int a[3003];
ll dp[3003][3003][2];
bool p[3003][3003][2];
ll s(int i,int j,int t){
    if(i>j){
        return 0;
    }
    ll &ret=dp[i][j][t];
    if(p[i][j][t])return ret;
    p[i][j][t]=1;
    ll ch1,ch2;
    if(t){
     ch1=s(i+1,j,1-t)-a[i];
     ch2=s(i,j-1,1-t)-a[j];
     return ret=min(ch1,ch2);
    }
    else{
         ch1=s(i+1,j,1-t)+a[i];
         ch2=s(i,j-1,1-t)+a[j];
        return ret=max(ch1,ch2);
    }
}

void solve(int T){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<s(0,n-1,0);
}

int main() {
    fastio

    int T=1;
    //cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
    }
	return 0;
}
