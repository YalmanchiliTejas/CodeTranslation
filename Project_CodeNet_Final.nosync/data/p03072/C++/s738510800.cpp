#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using ll = long long;
const ll MOD = 1e9+7; ll LLINF = 1LL << 60; int INF = INT_MAX;

//
int main(){
    int n; cin>>n;
    vector<int> h(n);
    rep(i,0,n) cin>>h[i];
    int maxi=0;
    int cnt=0;
    rep(i,0,n){
        if(h[i]>=maxi){
            cnt++;
            maxi=h[i];
        }
    }
    cout<<cnt<<endl;
}