#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

int N;
ll A[100010];

signed main(){
    cin >> N;
    REP(i, N) cin >> A[i];
    multiset<ll> mst;
    REP(i, N){
        auto l = mst.lower_bound(A[i]);
        if(l != mst.begin()){
            l--;
            mst.erase(l);
        }
        mst.insert(A[i]);
    }
    PRINT(mst.size());
    return 0;
}