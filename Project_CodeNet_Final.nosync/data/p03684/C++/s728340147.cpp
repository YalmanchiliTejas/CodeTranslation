#include <bits/stdc++.h>
using namespace std;

#define times(n, i)      uptil(0, n, i)
#define rtimes(n, i)     downto((n) - 1, 0, i)
#define upto(f, t, i)    for(int _##i = (t), i = (f); i <= _##i; i++)
#define uptil(f, t, i)   for(int _##i = (t), i = (f); i <  _##i; i++)
#define downto(f, t, i)  for(int _##i = (t), i = (f); i >= _##i; i--)
#define downtil(f, t, i) for(int _##i = (t), i = (f); i >  _##i; i--)
typedef long double ld;
#define long long long

#if defined(EBUG) && !defined(ONLINE_JUDGE)
    #define debug true
    #define ln << endl
#else
    #define debug false
    #define ln << '\n'
#endif
#define tb << '\t'
#define sp << ' '

const int MOD = 1e9+7;

class UnionFind{
    vector<int> pyon, rank;

    int root(int x){
        if(pyon[x] == -1) return x;
        else return pyon[x] = root(pyon[x]);
    }

public:
    UnionFind(int N): pyon(N, -1), rank(N, 1){}

    void merge(int x, int y){
        int rx = root(x), ry = root(y);
        if(rank[rx] < rank[ry]){
            pyon[rx] = ry;
        }else if(rank[rx] == rank[ry]){
            pyon[rx] = ry;
            rank[y]++;
        }else{
            pyon[ry] = rx;
        }
    }

    bool isSame(int x, int y){
        return root(x) == root(y);
    }
};


pair<long,int> xp[100010], yp[100010], dd[200020];

signed main() { // long: 64bit
    if(!debug) {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }

    int N;
    scanf("%d",&N);
    times(N, i) {
        long X, Y;
        scanf("%lld%lld",&X,&Y);
        xp[i] = {X, i};
        yp[i] = {Y, i};
    }
    sort(xp, xp+N);
    sort(yp, yp+N);
    times(N-1, i) {
        dd[i*2]   = {xp[i+1].first - xp[i].first, i*2};
        dd[i*2+1] = {yp[i+1].first - yp[i].first, i*2+1};
    }
    sort(dd, dd+N*2-2);

    if(debug) {
        times(N, i) cout << xp[i].first sp << xp[i].second tb; cout ln;
        times(N, i) cout << yp[i].first sp << yp[i].second tb; cout ln;
        times(N*2-2, i) cout << dd[i].first sp << dd[i].second tb; cout ln;
    }

    long ans = 0;
    UnionFind uf(N);
    times(N*2-2, i) {
        int j = dd[i].second / 2;
        if(dd[i].second % 2 == 0) { // x
            int a = xp[j].second, b = xp[j+1].second;
            if(!uf.isSame(a, b)) {
                uf.merge(a, b);
                ans += dd[i].first;
                if(debug) cout << i tb << 'x' tb << j tb << ans tb << dd[i].first tb << a tb << b ln;
            }
        } else {
            int a = yp[j].second, b = yp[j+1].second;
            if(!uf.isSame(a, b)) {
                uf.merge(a, b);
                ans += dd[i].first;
                if(debug) cout << i tb << 'y' tb << j tb << ans tb << dd[i].first tb << a tb << b ln;
            }
        }
    }

    cout << ans ln;

    return 0;
}
