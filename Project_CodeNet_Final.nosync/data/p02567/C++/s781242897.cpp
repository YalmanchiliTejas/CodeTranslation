#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;

#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

int op(int a, int b){
    return max(a, b);
}
int e() { return -1;}

int target;

bool op2(int v){
    return v < target;
}

int main() {
    int N, Q; 
    cin>> N >> Q;
    segtree<int, op, e> Seg(N);
    REP(i, 0, N){
        int a;
        cin >> a;
        Seg.set(i, a);
    }
    vi Query(3, 0);
    REP(i, 0, Q){
    }
    REP(i, 0, Q){
        REP(j, 0, 3) cin >> Query[j]; 
        if(Query[0] == 1){
            Seg.set(Query[1] - 1, Query[2]);
        }
        if(Query[0] == 2){
            int max = Seg.prod(Query[1] - 1, Query[2]);
            cout << max << endl;
        }
        if(Query[0] == 3){
            target = Query[2];
            int res = Seg.max_right<op2>(Query[1]-1) + 1;
            cout << res << endl;
        }
    }
}