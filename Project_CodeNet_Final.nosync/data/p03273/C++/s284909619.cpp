#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<b;i++)
inline constexpr ll intpow(ll a,ll b){if(b==0) return 1;ll ans=intpow(a,b/2);return ans*ans*(b&1?a:1);}


int main(){
    ll h,w;
    cin>>h>>w;
    vector<string>s(h);
    rep(i,0,h)cin>>s[i];
    vector<ll>cnt1(h),cnt2(w);
    rep(i,0,h)rep(j,0,w)if(s[i][j]=='#'){
        cnt1[i]++;
        cnt2[j]++;
    }
    rep(i,0,h)if(cnt1[i]){
        rep(j,0,w)if(cnt2[j])cout<<s[i][j];
        cout<<endl;
    }
}
