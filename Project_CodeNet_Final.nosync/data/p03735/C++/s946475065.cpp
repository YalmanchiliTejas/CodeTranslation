#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

template<class S, class T>
void psort(vector<S> &u, vector<T> &v, bool isGreater = false) {
    int n = (int)u.size();
    vector<pair<S, T>> vecP(n);
    for (int i = 0; i < n; ++i) {
        vecP[i].first = u[i];
        vecP[i].second = v[i];
    }
    if (isGreater) {
        sort(vecP.rbegin(), vecP.rend());
    }
    else {
        sort(vecP.begin(), vecP.end());
    }
    for (int i = 0; i < n; ++i) {
        u[i] = vecP[i].first;
        v[i] = vecP[i].second;
    }
}

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    vll X(N), Y(N);
    rep(i, N) {
        cin >> X[i] >> Y[i];
        // X[i]<=Y[i]とする
        if (X[i] > Y[i])swap(X[i], Y[i]);
    }
    /*
    最大値と最小値が同じ色になるかどうかで場合分けする
    とりあえず、最大値と最小値が異なる色になる場合について
    最大値を含む方は、大きい数を貪欲に
    最小値を含む方は、小さい数を貪欲に
    選ぶ。
    */
    ll rma = 0, rmi = INT_MAX, bma = 0, bmi = INT_MAX;
    rep(i, N) {
        smax(rma, X[i]);
        smin(rmi, X[i]);
        smax(bma, Y[i]);
        smin(bmi, Y[i]);
    }
    ll ans = (rma - rmi)*(bma - bmi);

    /*
    (X[i],Y[i])でソートする
    m, Mが同じ色に含まれる。
    (m, M)=(rmi, bma)
    他方の最小、最大は
    (z, Z)とする。
    zを昇順で見ていく。ただし、Zはできるだけ小さい方がいい。
    */
    psort(X, Y);
    int nm = 0, nM = 0;
    ll red = bma - rmi;
    // <値, id>
    set<pair<ll, int> > st, ts;
    rep(i, N) {
        st.insert(mp(X[i], i));
        ts.insert(mp(X[i], i));
        ts.insert(mp(Y[i], i));
        if (Y[i] == rmi)nm++;
        if (Y[i] == bma)nM++;
    }

    /*
    値aを取り除いてbを挿入
    */
    auto f = [&](ll a, ll b, int k) {
        if (X[k] != Y[k] && st.count(mp(a, k))) {
            st.erase(mp(a, k));
            st.insert(mp(b, k));
            if (a == rmi)nm++;
            if (a == bma)nM++;
            if (b == rmi)nm--;
            if (b == bma)nM--;
        }
    };

    [&] {
        each(p, ts) {
            /*
            zを最小値として固定
            */
            int k = p.second;
            ll z = p.first, w = X[k] ^ Y[k] ^ z;
            
            f(w, z, k);
            while (sz(st) && st.begin()->first < z) {
                ll u = st.begin()->first, v;
                int l = st.begin()->second;
                v = u ^ X[l] ^ Y[l];
                // すべての値をz以上にすることは不可能である。
                if (v < z) {
                    return;
                }
                f(u, v, l);
            }
            /*
            他方にm,Mが含まれている場合のみ計算
            */
            if (nm > 0 && nM > 0) {
                smin(ans, red*(st.rbegin()->first - st.begin()->first));
            }
        }
    }();
    cout << ans << endl;
}
