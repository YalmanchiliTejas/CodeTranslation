#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;
ll N;
ll A[201000];
map<l_l, ll> mp[201000];

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    //mp[0][{0, 1}] = 1e15;
    mp[0][{0, 1}] = 0;
    for(int i = 0; i < N; i++) {
        for(auto tmp : mp[i]) {
            ll num = tmp.first.first;
            ll ok = tmp.first.second;
            ll val = tmp.second;
            //cerr << i << " " << num << " " << ok << " " << (ll)(val - 1e15) << endl;
            //cerr << i << " " << num << " " << ok << " " << (ll)(val) << endl;
            if(ok) {
                ll newnum = num + 1;
                ll newok = 0;
                ll newval = val + A[i];
                if(abs(i/2 - newnum) <= 3) {
                    //cerr << "new: " << newnum << " " << newok << " " << newval << endl;
                    if(mp[i+1].count({newnum, newok})) chmax(mp[i+1][{newnum, newok}], newval);
                    else mp[i+1][{newnum, newok}] = newval;
                }
            }
            if(abs(i/2 - num) <= 3) {
                if(mp[i+1].count({num, 1})) chmax(mp[i+1][{num, 1}], val);
                else mp[i+1][{num, 1}] = val;
            }
        }
    }
    ll ans = mp[N][{N/2, 0}];
    chmax(ans, mp[N][{N/2, 1}]);
    cout << ans << endl;
    return 0;
}
