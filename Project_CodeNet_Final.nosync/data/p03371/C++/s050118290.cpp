#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a,b,c,x,y;cin>>a>>b>>c>>x>>y;
    ll ans = a*x + b*y;
    if(x>y){
        ans = min(c*y*2+a*(x-y), ans);
        ans = min(ans, c*x*2);
    } else{
        ans = min(c*x*2+b*(y-x), ans);
        ans = min(ans, c*y*2);
    }
    cout<<ans<<endl;

}