#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <cassert>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define INF 2140000000
//const long long MOD = 1000000007;
const long long MOD = 998244353;

using namespace std;


const long long INF2 = (((ll)1<<31)-1);

template<class T> class SegTree   // 0-indexed
{
private:
    int n;             // 葉の数
    vector<T> data;    // ノードの値を持つ配列
    vector<T> lazy;    // 遅延評価を持つ配列

    T def0;               // 初期値
    T def;                // 単位元
    
    T operation(T a, T b)    // 区間クエリで使う処理
    {
        return min(a, b);   // 区間minクエリ
        //return a+b;           // 区間和クエリ
    }

    void eval( int k, int l, int r )   // ノードkについて遅延評価を行う
    {
        if(lazy[k]) {
            data[k] += lazy[k];
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k];
                lazy[2*k+2] += lazy[k];     
            }
            lazy[k] = 0;
        }
        return;
    }

    void _add(int a, int b, T x, int k, int l, int r) {
        if(r < 0) r = n;
        eval(k, l, r);   // k 番目のノードに対して遅延評価を行う
        
        if(b <= l || r <= a) return;   // 範囲外なら何もしない
    
        // 完全に被覆しているならば、遅延配列に値を入れた後に評価
        if(a <= l && r <= b) {
            lazy[k] += x;
            eval(k, l, r);
        }

        // そうでないならば、子ノードの値を再帰的に計算して、
        // 計算済みの値をもらってくる
        else {
            _add(a, b, x, 2*k+1, l, (l+r)/2);
            _add(a, b, x, 2*k+2, (l+r)/2, r);
            data[k] = operation(data[2*k+1], data[2*k+2]);
        }
    }

    // 区間[a,b)の総和。ノードk=[l,r)に着目している。
    T _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return def; // 交差しない

        eval(k, l, r);
        if (a <= l && r <= b)
            return data[k]; // a,l,r,bの順で完全に含まれる
        else {
            T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子
            T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子
            return operation(c1, c2);
        }
    }
 
public:
    SegTree(int _n) {     // _n:必要サイズ
        //def = INF2;        // 初期値かつ単位元（minのときINF2)
        //def = 0;             // 初期値かつ単位元（和のとき0)
        def0 = 0;              // 初期値
        def  = LINF2;           // 単位元
        n = 1;
        while (n < _n) n *= 2;
        data = vector<T>(2 * n - 1, def0);
        lazy = vector<T>(2 * n - 1, 0);
    }

    // 区間更新
    void add(int a, int b, T x) {
        return _add(a, b, x, 0, 0, n);
    }

    // [a, b)の区間クエリを実行
    T query(int a, int b) {
        return _query(a, b, 0, 0, n);
    }
 
    // 添字でアクセス
    T operator[](int i) {
        return data[i + n - 1];
    }
};

ll dp[200005];   // 第i項を1にしたときの、第i項目までの得点の最大値

void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> l(m), r(m);
    vector<ll> a(m);
    vector<vector<int> > v0(n+1), v1(n+1);
    int i;
    for (i = 0; i < m; i++) {
        scanf("%d%d%lld", &l[i], &r[i], &a[i]); l[i]--;
        v0[l[i]].push_back(i);
        v1[r[i]].push_back(i);
    }

    SegTree<ll> S(n+2);

    for (i = 0; i <= n+1; i++) {
//#ifdef _DEBUG
#if 0
        {
            int k;
            for (k = 0; k < n; k++) {
                printf("[%d]%lld\n", k, S.query(k, k + 1));
            }
        }
#endif
        if(i > 0) {
            dp[i] = S.query(0, i);
            S.add(i, i+1, dp[i]);
        }
        if (i < n+1) {
            int k;
            for (k = 0; k < (int)v0[i].size(); k++) {
                int id=v0[i][k];
                S.add(0, l[id]+1, -a[id]);
            }
            for (k = 0; k < (int)v1[i].size(); k++) {
                int id=v1[i][k];
                S.add(0, l[id]+1, a[id]);
            }
        }
    }

    printf("%lld\n",-dp[n+1]);
    
    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T; scanf("%d", &T);
    while(T--) {
        solve();
    }
#endif
    return 0;
}
