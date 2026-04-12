#include<bits/stdc++.h>
using ll  = long long;
#define int ll
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define erep(e,v) for(auto && e :v)
#define all(in) in.begin(), in.end()
#define MP make_pair
#define INF (sizeof(int) == 4 ? (int)1e9:(int)1e18)
#define EPS 0.0000000001
using namespace std;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<typename Head, typename Value> auto vectors(const Head &head, const Value &v) { return vector<Value>(head, v); }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) { auto inner = vectors(tail...); return vector<decltype(inner)>(x, inner); }
template<class T> void join(T a){for(auto itr :a){if(itr != *a.begin())cout << " "; cout << itr;} }
using ld  = long double;
using pii = pair<int,int>;
using piii = pair<int,pii>;
int W,H;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
bool valid(int x,int y){return (0<=x&&x<W)&&(0<=y&&y<H);}
#define JOINT(A,B) int A##B
vector<int>dp(51,0LL),dp2(51,0LL);
signed main(){
    int n,x; cin >> n >> x;
    rep(i,51){
        if(i == 0){
            dp[0] = dp2[0] = 1LL;
        } else {
            dp[i] = dp[i-1] + dp[i-1] + 3;
            dp2[i] = dp2[i-1] + dp2[i-1] + 1;
        }
    }
    function<int(int,int)>cal = [&](int i,int x) -> int{
        if(x == 0)return 0LL;
        if(i == 0)return 1LL;
        if(dp[i-1] + 2 >= x){
            return cal(i-1,x-1) + (dp[i-1] + 2 == x);
        } else {
            return cal(i-1,x - dp[i-1] - 2) + dp2[i-1] + 1;
        }
    };
    cout << cal(n,x) << endl;
}
