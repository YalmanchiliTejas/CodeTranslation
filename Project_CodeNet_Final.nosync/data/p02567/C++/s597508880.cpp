#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
const ll MOD=1000000007;
const ll LINF=1ll<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0,1,-1,1,-1};
int dy[]={0,1,0,-1,1,-1,-1,1};

ll op(ll a, ll b){
    return max(a, b);
}

ll e(){
    return -LINF;
}

int main(){
    int n,q;cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto seg = segtree<ll, op, e> (a);
    while(q--){
        ll t,a,b;cin >> t >> a >> b;
        if(t == 1){
            a--;
            seg.set(a, b);
        }
        else if(t == 2){
            a--;
            cout << seg.prod(a, b) << endl;
        }
        else{
            a--;
            auto f = [&](ll x){
                return x < b;
            };
            cout << seg.max_right(a, f) + 1 << endl;
        }
    }
    return 0;
}
