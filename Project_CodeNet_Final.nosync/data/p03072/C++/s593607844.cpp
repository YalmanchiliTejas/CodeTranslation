#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define rep(i,n) for(ll i=0;i<n;i++)
#define INF 1e9+7
#define LLINF 1e18
using namespace std;
const ll MOD = 1e9 +7;

int main(){
    int n,h[110],ans=0;
    cin>>n;
    rep(i,n) cin>>h[i];
    rep(i,n){
        bool can=true;
        rep(j,i){
            if(h[j]>h[i]) can=false;
        }
        if(can) ans++;
    }
    cout <<ans<<endl;
    return 0;
}