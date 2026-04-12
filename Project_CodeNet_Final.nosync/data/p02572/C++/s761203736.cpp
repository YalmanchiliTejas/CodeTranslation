#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define mem0(x) memset(x,0,sizeof(x))
#define meminf(x) memset(x,0x3f,sizeof(x))
#define VI vector<int>
#define VL vector<ll>
using namespace  std;

const int N = 2e5+5;
const ll modd = 1e9+7;
ll a[N];
int main(){
    ios::sync_with_stdio(0);
    int n;cin>>n;ll sum = 0;
    rep(i,1,n){
        cin>>a[i]; sum  = (sum+a[i])%modd;
    }
    ll ans = 0;
    sum = ((sum - a[1])%modd + modd)%modd;
    rep(i,1,n-1){
        ans  = (ans + a[i]*sum)%modd;
        sum = ((sum - a[i+1])%modd + modd)%modd;
    }
    cout<<ans;
}
