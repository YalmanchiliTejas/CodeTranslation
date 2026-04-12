#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using P = pair<ll, ll>;

// chmin, chmax関数
template<typename T, typename U, typename Comp=less<>>
bool chmax(T& xmax, const U& x, Comp comp={}) {
    if(comp(xmax, x)) {
        xmax = x;
        return true;
    }
    return false;
}
template<typename T, typename U, typename Comp=less<>>
bool chmin(T& xmin, const U& x, Comp comp={}) {
    if(comp(x, xmin)) {
        xmin = x;
        return true;
    }
    return false;
}

//---------------------------

using VSL = vector<set<ll>>;

int main(){
    ll n,m;
    cin >> n >> m;
    VSL G(n+1);
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        G[a].insert(b);
        G[b].insert(a);
    }

    VL perm(n-1);
    rep(i,n-1){
        perm[i] = i + 2;
    }

    ll ans = 0;
    do {
        ll cur = 1;
        bool flag = true;
        rep(i,n-1){
            ll next = perm[i];
            if(G[cur].count(next)){
                cur = next;
            }else{
                flag = false;
                break;
            }
        }
        if(flag) ans++;

        // for(auto x : perm){
        //     cout << x << " ";
        // }
        // cout << endl;
        // if(flag) cout << "Okay" << endl;

    } while (next_permutation(perm.begin(), perm.end()));

    cout << ans << endl;

    return 0;
}