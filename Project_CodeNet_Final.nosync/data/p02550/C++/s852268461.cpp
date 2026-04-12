#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll, ll> P;
using VP = vector<P>;
using VVP = vector<VP>;
using VI = vector<ll>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
const int inf = 1e9 + 7;
const ll INF = 1LL << 61;
const ll mod = 1e9 + 7;

template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int i, j;
    ll n,x,m;
    cin >> n >> x >> m;
    ll loop, loopsum, st;
    ll ans = 0;
    ans += x/m * m;
    x = x%m;
    VI v(m+1,0);
    v[x] = 1;
    VI sum(m+1,0);
    sum[1] = x;
    for(i=2;i<=101010;i++){
        x = (x * x) % m;
        sum[i] = sum[i-1] + x;
        if(v[x] > 0){
            loop = i - v[x];
            loopsum = sum[i] - sum[v[x]];
            st = v[x];
            break;
        }
        else {
            v[x] = i;
        }
    }
    if(n<=st+loop){
        cout<<sum[n]<<endl;
        return 0;
    }
    else{
        n -= st;
        ans += sum[st];
        ans += (n/loop) * loopsum;
        ll rest = n % loop;
        ans += sum[st+rest] - sum[st];
    }
    cout<<ans<<endl;

}