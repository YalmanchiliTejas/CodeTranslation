//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod =1e+9+7;

const int dy[4]={0,1,0,-1};
const int dx[4]={1,0,-1,0};
const ll INF=1e10;

int main(){
    ll n; cin>>n;
    vector<ll>a(n);
    ll sum=0;
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
        sum%=mod;
    }
    ll ans=0;
    rep(i,n-1){
        sum-=a[i];
        if(sum<0)sum+=mod;
        ans+=a[i]*sum;
        ans%=mod;
    }
    cout<<ans<<endl;

}











































































