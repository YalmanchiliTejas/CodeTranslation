#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,int>
#define T tuple<int,int,int> 
using namespace std;

vector<ll> sizes;

ll solve(ll n,ll x){
    if(n==0) return 1;
    if(x<=1) return 0;
    if(x<=1+sizes[n-1]) return solve(n-1,x-1);
    if(x==2+sizes[n-1]) return solve(n-1,sizes[n-1])+1;
    if(x<sizes[n]-1){
        ll zan=x-2-sizes[n-1];
        return solve(n-1,sizes[n-1])+solve(n-1,zan)+1;
    }
    else return solve(n-1,sizes[n-1])*2+1;
}

int main(){
    ll n,x; cin >> n >> x;
    sizes.resize(51);
    sizes[0]=1;
    rep(i,51){
        sizes[i+1]=sizes[i]*2+3;
    }
    ll ans=solve(n,x);
    cout << ans << endl;
return 0;
}
