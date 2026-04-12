#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define repd(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template

// Starry Sky Tree: range add segment tree
class StarrySkyTree {
public:
    static const int N = 1 << 20; // 2^20 = 1048576
    vector<ll> segMin, segMax, segAdd;
    
    StarrySkyTree(): segMin(N * 2, (ll)1e18), segMax(N * 2, (ll)-1e18), segAdd(N * 2, 0) {}
    
    // update k-th element to x: O(logN)
    void update(int k, long long x) {
        k += N - 1;
        segMin[k] = x;
        segMax[k] = x;
        while (k) {
            k = (k - 1) / 2;
            segMin[k] = min(segMin[k * 2 + 1], segMin[k * 2 + 2]);
            segMax[k] = max(segMax[k * 2 + 1], segMax[k * 2 + 2]);
        }
    }

    
    // range add [a, b) += x: O(log^2 N)
    // k = 0, l = 0, r = N, N: power of 2
    void add(int a, int b, ll x, int k = 0, int l = 0, int r = N){
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            segAdd[k] += x;
            while (k) {
                k = (k - 1) / 2;
                segMin[k] = min(segMin[k * 2 + 1] + segAdd[k * 2 + 1], segMin[k * 2 + 2] + segAdd[k * 2 + 2]);
                segMax[k] = max(segMax[k * 2 + 1] + segAdd[k * 2 + 1], segMax[k * 2 + 2] + segAdd[k * 2 + 2]);
            }
            return;
        }
        add(a, b, x, k * 2 + 1, l, (l + r) / 2);
        add(a, b, x, k * 2 + 2, (l + r) / 2, r);
    }
    
    // RMQ: O(logN)
    // k = 0, l = 0, r = N
    ll getMin(int a, int b, int k = 0, int l = 0, int r = N) {
        if (r <= a || b <= l) return 1e18;
        if (a <= l && r <= b) return segMin[k] + segAdd[k];
        ll x = getMin(a, b, k * 2 + 1, l, (l + r) / 2);
        ll y = getMin(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(x, y) + segAdd[k];
    }
    
    ll getMax(int a, int b, int k = 0, int l = 0, int r = N) {
        if (r <= a || b <= l) return -1e18;
        if (a <= l && r <= b) return segMax[k] + segAdd[k];
        ll x = getMax(a, b, k * 2 + 1, l, (l + r) / 2);
        ll y = getMax(a, b, k * 2 + 2, (l + r) / 2, r);
        return max(x, y) + segAdd[k];
    }
    
};

void debug(int a, int b){
//    cout << "l: " << a << ", " << "r: " << b << endl;
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    int N;
    cin >> N;
    vector<int> S(N);
    int sz = N / 2;
    rep(i, N) cin >> S[i];
    rep(i, sz){
        S[i] -=  S[N - i - 1];
    }
    int Q;
    cin >> Q;
    
    StarrySkyTree sst;
    rep(i, sz) sst.update(i, S[i]);
    
    rep(i, Q){
        int l, r;
        ll x;
        cin >> l >> r >> x;
        l--, r--;
        if (r < sz) {
            sst.add(l, r + 1, x);
//            debug(l, r + 1);
        }
        else if(l >= (N + 1) / 2){
            sst.add(N - r - 1, N - l, -x);
//            debug(N - r - 1, N - l);
        }
        else{
            sst.add(l, sz, x);
            sst.add(N - r - 1, sz, -x);
//            debug(l, sz);
//            debug(N - r - 1, sz);
        }
        
        if (sst.getMax(0, sz) == 0 && sst.getMin(0, sz) == 0) {
            output(1, 0);
        }
        else{
            output(0, 0);
        }
        
    }
    
    return 0;
}