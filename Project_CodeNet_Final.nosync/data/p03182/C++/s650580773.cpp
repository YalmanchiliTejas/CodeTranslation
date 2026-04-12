#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define int long long
#define INF 1000000000000000000
using namespace std;

#define ANS(f) if(f) cout << "YES" << endl; else cout << "NO" << endl;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }
void debug(mat m){REP(i, m.size()){ REP(j, m[i].size()){ cout << m[i][j] << ","; } cout << endl; }}

class Lazy_segment_tree
{
    using data_type = int;

public:

    vector<data_type> dat, lazy;
    int N;
    data_type id, id2;

    //区間演算結果を求めるクエリに関する演算
    data_type func(data_type u, data_type v){
        return max(u, v);
    }
    //区間更新に関する演算
    data_type func2(data_type u, data_type v){
        return u + v;
    }
    //作用素同士の演算
    data_type func3(data_type u, data_type v){
        return u + v;
    }

    Lazy_segment_tree(int n, data_type id, data_type id2): id(id), id2(id2) {
        N = 1;
        while(n > N) N = N << 1;
        dat = vector<data_type>(2 * N - 1, id);
        lazy = vector<data_type>(2 * N - 1, id2);
    }

    Lazy_segment_tree(int n, data_type id, data_type id2, vector<data_type> v): id(id), id2(id2) {
        N = 1;
        while(n > N) N = N << 1;
        dat = vector<data_type>(2 * N - 1, id);
        lazy = vector<data_type>(2 * N - 1, id2);
        REP(i, n) dat[i + N - 1] = v[i];
        IREP(i, N - 1) dat[i] = func(dat[i * 2 + 1], dat[i * 2 + 2]); 
    }

    //遅延評価
    void eval(int k, int l, int r){
        if(lazy[k] != id2){
            //子ノード数に比例した量の演算をする場合
            //dat[k] = func2(dat[k], lazy[k] * (r - l));
            //子ノード数に依存しない場合
            dat[k] = func2(dat[k], lazy[k]);

            if(r - l > 1){
                lazy[k * 2 + 1] = func3(lazy[k * 2 + 1], lazy[k]);
                lazy[k * 2 + 2] = func3(lazy[k * 2 + 2], lazy[k]);
            }

            lazy[k] = id2;
        }
    }

    void update(int a, int b, data_type x, int k, int l, int r){

        eval(k, l, r);

        if(b <= l || r <= a) return;

        if(a <= l && r <= b){
            lazy[k] = func3(lazy[k], x);
            eval(k, l, r);
        }else{
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);
            dat[k] = func(dat[k * 2 + 1], dat[k * 2 + 2]);
        }

    }

    data_type query(int a, int b, int k, int l, int r){
        if(r <= a || b <= l) return id;

        eval(k, l, r);
        if(a <= l && r <= b) return dat[k];
        else{
            data_type vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            data_type vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return func(vl, vr);
        }
    }

    //[a,b)の区間更新
    void update(int a, int b, data_type x){
        update(a, b, x, 0, 0, N);
    }

    //[a, b)の演算結果
    data_type query(int a, int b){
        return query(a, b, 0, 0, N);
    }

    data_type getdat(int k){
        return query(k, k + 1);
    }
};

signed main(){

    int N, M; cin >> N >> M;
    vec l(M), r(M), a(M);
    mat lx(N + 1, vec(0)), rx(N + 1, vec(0));
    REP(i, M){
        cin >> l[i] >> r[i] >> a[i];
        lx[l[i]].push_back(i);
        rx[r[i]].push_back(i);
    }

    Lazy_segment_tree T(N + 1, -INF, 0, vec(N + 1, 0));
    FOR(i, 1, N + 1){
        for(int j: lx[i]) T.update(0, l[j], a[j]);
        T.update(i, i + 1, T.query(0, i));
        for(int j: rx[i]) T.update(0, l[j], -a[j]);
    }
    cout << T.query(0, N + 1);
    
    return 0;
}