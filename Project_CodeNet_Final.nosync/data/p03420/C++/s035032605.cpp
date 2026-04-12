#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n,k; cin>>n>>k;
    if(k==0){
        cout<<n*n<<endl;
        return 0;
    }
    ll res=0;
    for(ll b=1; b<=n; b++){
        if(b<=k) continue;
        res+=(b-k)*(n/b);
        res+=max(0ll, n%b-k+1);
    }
    cout<<res<<endl;
    return 0;
}