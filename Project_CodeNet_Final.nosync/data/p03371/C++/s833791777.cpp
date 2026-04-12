#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(v) v.begin(), v.end()
#define PI 3.141592653589793238462643383279
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;
const long long MOD = 1e9+7;
const ll INF = 1LL << 60;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    //abピザをk枚買ったとき、aピザはmax(x - k,0),bピザはmax(y-k,0)
    int ans = INT_MAX;
    for(int i = 0; i < (int)1e5+1; i++){
        ans = min(ans,2*c*i+a*max(x-i,0)+b*max(y-i,0));
    }
    cout << ans << endl;
}