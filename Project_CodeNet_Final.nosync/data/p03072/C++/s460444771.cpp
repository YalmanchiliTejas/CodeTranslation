#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define int long long
#define double long double
#define mod 1000000007
#define F first
#define S second
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
#define INF 1000000000000000
#define endl '\n'
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    vector<int> h(n);
    rep(i,n)cin>>h.at(i);
    int ans=0;
    rep(i,n){
        bool can=true;
        for(int j=0; j<i; j++){
            if(h.at(i)<h.at(j))can=false;
        }
        if(can)ans++;
    }
    cout<<ans<<endl;
}