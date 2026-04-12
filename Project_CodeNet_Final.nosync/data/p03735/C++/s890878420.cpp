#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
typedef long long ll;

template <class T> struct SegmentTreeMin {
    
    int N;
    vector<T> node;
    const T INF = numeric_limits<T>::max() / 2;

    SegmentTreeMin (int n) { 
        N = 2 << (int)log2(n);
        node.resize(N*2, INF); 
    }
  
    void update(int idx, T val){
        idx += N;
        node[idx] = val;
        while (idx > 0) {
            node[idx>>1] = min(node[idx], node[idx^1]);
            idx >>= 1;
        }
    }

    T get_min(int l, int r) { 
        T ret = INF;
        l += N, r += N;
        while (l < r) {
            if (l & 1) ret = min(ret, node[l++]);
            if (r & 1) ret = min(ret, node[--r]);
            l >>= 1; r >>= 1;
        }
        return ret;
    }
    
};

template <class T> struct SegmentTreeMax {

    int N;
    vector<T> node;
    const T INF = numeric_limits<T>::min() / 2;
  
    SegmentTreeMax (int n) {
        N = 2 << (int)log2(n);
        node.resize(N*2, INF); 
    }
  
    void update(int idx, T val){
        idx += N;
        node[idx] = val;
        while (idx > 0) {
            node[idx>>1] = max(node[idx], node[idx^1]);
            idx >>= 1;
        }
    }
  
    T get_max(int l, int r) { 
        T ret = INF;
        l += N, r += N;
        while (l < r) {
            if (l & 1) ret = max(ret, node[l++]);
            if (r & 1) ret = max(ret, node[--r]);
            l >>= 1; r >>= 1;
        }
        return ret;
    }

};

int main ()
{
    int N; cin >> N;
    vector < ll > x(N),y(N);
    REP(i,N) cin >> x[i] >> y[i];

    vector < pair < ll,ll > > ord;
    REP(i,N) ord.push_back(make_pair(min(x[i],y[i]), i));
    sort(ord.begin(), ord.end());
    SegmentTreeMax < ll > Rmax(200010),Bmax(200010);
    SegmentTreeMin < ll > Rmin(200010),Bmin(200010);
    REP(i,N) {
        Rmax.update(i, max(x[i],y[i]));
        Rmin.update(i, max(x[i],y[i]));
        Bmax.update(i, min(x[i],y[i]));
        Bmin.update(i, min(x[i],y[i]));
    }
    ll ans = abs(Rmax.get_max(0,200005) - Rmin.get_min(0,200005)) * 
             abs(Bmax.get_max(0,200005) - Bmin.get_min(0,200005));
    REP(i,N) {
        int idx = ord[i].second;
        Rmax.update(idx, min(x[idx],y[idx]));
        Rmin.update(idx, min(x[idx],y[idx]));
        Bmax.update(idx, max(x[idx],y[idx]));
        Bmin.update(idx, max(x[idx],y[idx]));
        ll anst = abs(Rmax.get_max(0,200005) - Rmin.get_min(0,200005)) * 
                  abs(Bmax.get_max(0,200005) - Bmin.get_min(0,200005));
        ans = min(ans, anst);
    }

    cout << ans << endl;

    return 0;
}
