#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define is(a, b) a == b
#define len(v) ll(v.size())

const ll INF = 1LL << 58;

//xより以下の要素へのindex
template <class T> int former(const vector<T> &v, T x) {
  return upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
}
//x以上の要素へのindex
template <class T> int latter(const vector<T> &v, T x) {
  return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    ll ans=pow(10,10);
    for(ll i=0;i<max(x,y)*2+1;i=i+2){
        if(c*i+a*max(ll(0),x-i/2)+b*max(ll(0),y-i/2)<ans){
            ans=c*i+a*max(ll(0),x-i/2)+b*max(ll(0),y-i/2);
        }
    }
    cout<<ans<<endl;
}