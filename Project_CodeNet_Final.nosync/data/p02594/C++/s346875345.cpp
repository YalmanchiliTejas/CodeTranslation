#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n);++i)
using namespace std;
using ll = long long; 
using P = pair<int,int>;
using vv = vector<vector<ll> >;
template <class _t> inline bool chmax (_t& a,_t b){if(a<b){a=b;return true;}return false;} template <class _t> inline bool chmin (_t& a,_t b){if(a>b){a=b;return true;}return false;}

const int INF = 2147483647;
const int max_N = 1000000000;
const long long inf = 1ll << 60;
const long long mod = 1000000007;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int main(){
    int n;cin >> n;
    if(n>=30) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
