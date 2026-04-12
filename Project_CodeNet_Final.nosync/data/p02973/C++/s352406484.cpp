#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n; cin>>n;
    vector<ll> c={-1};
    rep(i,n){
        ll a; cin>>a;
        ll s=c.size();
        if(c[0]<a){
            c[0]=a;
            continue;
        }
        ll left=0, right=s;
        while(left+1<right){
            ll mid=(left+right)/2;
            if(a>c[mid]) right=mid;
            else left=mid;
        }
        if(right==s) c.push_back(a);
        else c[right]=a;
    }
    cout<<c.size()<<endl;
    return 0;
}