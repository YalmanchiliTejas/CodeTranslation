#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n; cin>>n;
    vector<ll> col={-1};
    rep(i,n){
        ll a; cin>>a;
        ll len=col.size();
        if(col[0]<a){
            col[0]=a;
        }else{
            ll left=0, right=len;
            while(right-left>1){
                ll mid=(left+right)/2;
                if(col[mid]>=a) left=mid;
                else right=mid;
            }
          	if(right==len) col.push_back(a);
            else col[right]=a;
        }
        //rep(j, col.size()) cout<<col[j]<<' ';
    }
    cout<<col.size()<<endl;
    return 0;
}
