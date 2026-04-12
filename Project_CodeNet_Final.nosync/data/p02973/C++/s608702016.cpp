#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <cmath> // 変数名にy1が使えなくなるかも…。
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <functional>
#include <string>

typedef __int128_t int128_t;
std::istream &operator>>(std::istream& input, int128_t& value) { // int128_tの入力。入力が64bitに収まる前提。
    long long tmp; input >> tmp; value = tmp;
    return input;
}
std::ostream &operator<<(std::ostream& output, const int128_t value) { // int128_tの出力。出力が64bitに収まる前提。
    output << (long long)value;
    return output;
}

// binary search result
struct BSR {
    bool found; // 条件を満たす範囲が見つかったか。falseの場合、begin,endは意味を持たない。
    int128_t begin; // [begin, end]で条件が成り立つ。
    int128_t end;
    BSR(bool found_in, int128_t begin_in, int128_t end_in) { found = found_in; begin = begin_in; end = end_in; }
    //BSR(bool found_in, int128_t begin_in, int128_t end_in) : found(found_in), begin(begin_in), end(end_in) {}
};

//template<class Fn> BSR binary_search(int128_t L, int128_t R, Fn func) {
BSR binary_search(int128_t L, int128_t R, std::function<bool(int128_t)> func) {
    const bool res_L = func(L);
    const bool res_R = func(R);
    if (res_L && res_R) {
        return BSR(true, L, R);
    } else if (!res_L && !res_R) {
        return BSR(false, 0, 0);
    } else {
        int128_t lb = L;
        int128_t ub = R;
        while (lb + 1 < ub) {
            int128_t mid = (lb + ub) / 2;
            if (res_L == func(mid)) {
                lb = mid;
            } else {
                ub = mid;
            }
        }
        return res_L ? BSR(true, L, lb) : BSR(true, ub, R);
    }
}

// range_query
enum RQ_type {
    MAX_MAX, // 更新クエリ: i:[l, r]に対して、x[i] = max(x[i], o). 求値クエリ: i:[l, r]に対して max(x[l],...,x[r]).
    MIN_MIN, // 更新クエリ: i:[l, r]に対して、x[i] = min(x[i], o). 求値クエリ: i:[l, r]に対して min(x[l],...,x[r]).
    ADD_MAX, // 更新クエリ: i:[l, r]に対して、x[i] += o.           求値クエリ: i:[l, r]に対して max(x[l],...,x[r]).
    ADD_MIN, // 更新クエリ: i:[l, r]に対して、x[i] += o.           求値クエリ: i:[l, r]に対して min(x[l],...,x[r]).
    SUB_MAX, // 更新クエリ: i:[l, r]に対して、x[i] = o.            求値クエリ: i:[l, r]に対して max(x[l],...,x[r]).
    SUB_MIN, // 更新クエリ: i:[l, r]に対して、x[i] = o.            求値クエリ: i:[l, r]に対して min(x[l],...,x[r]).
    ADD_SUM, // 更新クエリ: i:[l, r]に対して、x[i] += o.           求値クエリ: i:[l, r]に対して sum(x[l],...,x[r]).
    MANUAL, // 手動で任意のものを与える場合。
};

template <RQ_type rqt>
class Range_Query {
    public:

    int n;
    std::vector<int128_t> data, lazy;
    Range_Query() {}
    Range_Query(const int size) {
        // 要素数を2のべき乗にする。
        // kの子をk*2+1,k*2+2とするやり方は、0-index配列に準拠している。1-indexの配列に適用することも考えて、
        // x[0]...x[size]が問題なく確保出来るよう、nはsize+1以上の2冪にする。
        n = 1;
        while (n < size + 1) {
            n *= 2;
        }
        data.resize(n*2, id_val());
        lazy.resize(n*2, id_op());
    }

    // 全てを初期値に戻す。セグメント木を何度も利用する場合に用いる。
    void reset() {
        for (int i = 0; i < data.size(); i++) {
            data[i] = id_val(); lazy[i] = id_op();
        }
    }

    // 求値クエリに寄与しない値。
    // op1(v, id_val()) = op1(id_val(), v) = v となるもの。
    int128_t id_val() {
        switch(rqt) {
            case MAX_MAX:
            case ADD_MAX:
            case SUB_MAX:
                return std::numeric_limits<int64_t>::min();
                // データをint128_tとしているのは、modの取り忘れ等でオーバーフローしないためであり、最大値最小値などは64bitに収まる想定。
                // std::numeric_limits<int128_t>は出力が未定義で適切に存在するのか不明なので使わない。
                // 最小値として別の値(0など)を用いるべきケースでは、適切に初期化クエリを行うこと。
                // 加算クエリなら update(1, N, -rq.id_val())、それ以外なら update(1, N, 0)とすれば、[1,N]を0にできる。
            case MIN_MIN:
            case ADD_MIN:
            case SUB_MIN:
                return std::numeric_limits<int64_t>::max();
            case ADD_SUM:
                return 0;
            case MANUAL:
                assert(false);
                return 0;
        }
    }

    // 更新操作の単位元。何も更新しない操作。
    // op2(v, id_op()) = v, op3(o, id_op()) = op3(id_op(), o) = o となるもの。
    int128_t id_op() {
        switch(rqt) {
            case MAX_MAX:
            case SUB_MIN:
            case SUB_MAX:
                return std::numeric_limits<int64_t>::min();
                // 更新操作が代入の場合、正しくは単位元のフラグが必要だが、int64_tの最小値をフラグ代わりに利用する。
                // 実際に数列の値をint64_tの最小値にすることは論理的にできなくなることに注意。
            case MIN_MIN:
                return std::numeric_limits<int64_t>::max();
            case ADD_MAX:
            case ADD_MIN:
            case ADD_SUM:
                return 0;
            case MANUAL:
                assert(false);
                return 0;
        }
    }

    // 求値クエリにおいて、2つの値を1つの値に結合する演算。
    int128_t op1(int128_t v1, int128_t v2) {
        switch(rqt) {
            case MAX_MAX:
            case ADD_MAX:
            case SUB_MAX:
                return std::max(v1, v2);
            case MIN_MIN:
            case ADD_MIN:
            case SUB_MIN:
                return std::min(v1, v2);
            case ADD_SUM:
                return v1 + v2;
            case MANUAL:
                assert(false);
                return 0;
        }
    }

    // 更新操作。以下の2つの条件のうち、どちらかが成り立つ必要がある。
    // 条件1: 2つの値を結合してから更新操作した値と、2つの値に更新操作してから結合した値が等しい。すなわち
    // op2(op1(v1, v2), o) = op1(op2(v1, o), op2(v2, o))
    // 条件2: 2つの値を結合してから、2倍の更新操作をした値と、2つの値に更新操作してから結合した値が等しい。すなわち
    // op2(op1(v1, v2), o*2) = op1(op2(v1, o), op2(v2, o))
    // 条件2を満たす場合、各ノードでの更新は、対応する区間長さを係数とする操作を行う。
    int128_t op2(int128_t v, int128_t o, const int l, const int r) {
        switch(rqt) {
            case MAX_MAX:
                return std::max(v, o);
            case MIN_MIN:
                return std::min(v, o);
            case ADD_MAX:
            case ADD_MIN:
                return v + o;
            case SUB_MAX:
            case SUB_MIN:
                return o == id_op() ? v : o;
            case ADD_SUM:
                return v + o * (r - l);
            case MANUAL:
                assert(false);
                return 0;
        }
    }

    // 更新操作のマージ
    // 2つの更新操作を2度行った結果と、2つの更新操作を1つにまとめた更新操作を1度行った結果が等しくなる必要がある。すなわち
    // op2(op2(v, o1), o2) = op2(v, op3(o1, o2)) 
    int128_t op3(int128_t o1, int128_t o2) {
        switch(rqt) {
            case MAX_MAX:
                return std::max(o1, o2);
            case MIN_MIN:
                return std::min(o1, o2);
            case ADD_MAX:
            case ADD_MIN:
            case ADD_SUM:
                return o1 + o2;
            case SUB_MAX:
            case SUB_MIN:
                return o2 == id_op() ? o1 : o2;
            case MANUAL:
                assert(false);
                return 0;
        }
    }

    void push(const int k, const int l, const int r) { // node に対して、lazyの操作を行い、子のノードに伝播する。lazy[k]は単位元に戻す。
        if (lazy[k] == id_op()) { return; }
        if (k < n - 1) {
            lazy[k*2 + 1] = op3(lazy[k*2 + 1], lazy[k]);
            lazy[k*2 + 2] = op3(lazy[k*2 + 2], lazy[k]);
        }
        data[k] = op2(data[k], lazy[k], l, r);
        lazy[k] = id_op();
    }

    // データ配列の区間[a,b)の連結値を求める。
    // k:探索しているセグメント木の節点のセグメント木配列番号
    // [l, r):kに対応する区間
    int128_t query_child(const int a, const int b, const int k, const int l, const int r) {
        if (r <= a || b <= l) { return id_val(); }
        if (a <= l && r <= b) { return op2(data[k], lazy[k], l, r); }
        push(k, l, r);

        int128_t vl = query_child(a, b, k*2 + 1, l, (l+r)/2);
        int128_t vr = query_child(a, b, k*2 + 2, (l+r)/2, r);
        return op1(vl, vr);
    }

    // データ配列の区間[a,b]の連結値を求める。query_childと異なり閉区間
    int128_t query(const int a, const int b) {
        return query_child(a, b+1, 0, 0, n);
    }

    // [a, b)の区間に、oで表される演算を行う。
    // k:探索しているセグメント木の節点のセグメント木配列番号
    // [l, r):kに対応する区間
    void update_child(const int a, const int b, const int k, const int l, const int r, int128_t o) {
        if (r <= a || b <= l) { return; }
        if (a <= l && r <= b) { 
            lazy[k] = op3(lazy[k], o);
            return;
        }
        push(k, l, r);
        const int mid = (l + r) / 2;
        update_child(a, b, k*2 + 1, l, mid, o);
        update_child(a, b, k*2 + 2, mid, r, o);
        data[k] = op1(op2(data[k*2 + 1], lazy[k*2 + 1], l, mid), op2(data[k*2 + 2], lazy[k*2 + 2], mid, r));
    } 

    // データ配列の区間[a,b]に、oで表される演算を行う。update_childと異なり閉区間
    void update(const int a, const int b, int128_t o) {
        update_child(a, b+1, 0, 0, n, o);
    }

    // データ配列の要素1つに、oで表される演算を行う。
    void update_spot(const int a, int128_t o) {
        update_child(a, a+1, 0, 0, n, o);
    }
};

#define rep(i, begin, end) for(int64_t i = (begin); i <= (end); i++)
#define rev(i, begin, end) for(int64_t i = (begin); (end) <= i; i--)

void printvec(const std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) { std::cout << vec[i] << " "; } std::cout << std::endl;
}

const int MAX_N = 1e5 + 10;
int N;
int A[MAX_N];

std::unordered_map<int, std::vector<int>> mp;
Range_Query<SUB_MAX> rq = Range_Query<SUB_MAX>(MAX_N);

int main(int argc, char **argv) {
    std::cin >> N;
    rep (i, 1, N) {
        std::cin >> A[i];
        mp[A[i]].push_back(i);
        rq.update_spot(i, A[i]);
    }

    //std::cout << rq.query(1, 4) << std::endl;
    //std::cout << rq.query(4,4) << std::endl;
    //return 0;

    for (auto p : mp) {
        std::reverse(p.second.begin(), p.second.end());
        mp[p.first] = p.second;
        //printvec(p.second);
    }

    //printvec(mp[0]);

    int rest = N;
    int color = 0;

    while (0 < rest) {
        int right = N;
        while (true) {
            //std::cout << "q:" << right << std::endl;
            int max = rq.query(1, right);
            if (max < 0) {
                break;
            }
            //std::cout << right << " " << max << std::endl;
            assert(0 < mp[max].size());
            int pos = mp[max].back();
            //std::cout << right << " " << pos << " " << max << " " << std::endl;
            mp[max].pop_back();
            rq.update_spot(pos, -1);
            rest--;
            right = pos - 1;

            //std::cout << "c:" << " " << rq.query(pos, pos) << std::endl;

            if (right < 1) {
                break;
            }
        }
        color++;
        //std::cout << "r:" << color << " " << rest << std::endl;
    }

    std::cout << color << std::endl;

    
    
    return 0;
}