#include <iostream>
#include <vector>
#include <tuple>
#include <functional>

using Int = long long int;
using std::pair;
using std::vector;

template <class Data, class Operator>
class LazySegmentTree {
    using DataMerger = std::function<Data(Data, Data)>;
    using OperatorMerger = std::function<Operator(Operator, Operator)>;
    using Applier = std::function<Data(Data, Operator, int)>;

private:
    int length;
    std::vector<Data> dat;
    std::vector<Operator> ope;
    Data dat_id;            // データの単位元
    Operator ope_id;        // 作用素の単位元
    DataMerger dmerge;      // データをマージする関数
    OperatorMerger omerge;  // 作用素をマージする関数
    Applier app;            // データに作用素を適用する関数 第三引数に区間長を取る

    void eval(int nidx, int len) {
        if (ope[nidx] == ope_id) return;
        // 子に作用素を伝播
        if (nidx * 2 + 1 < length * 2) {
            ope[nidx * 2] = omerge(ope[nidx * 2], ope[nidx]);
            ope[nidx * 2 + 1] = omerge(ope[nidx * 2 + 1], ope[nidx]);
        }
        // 値に作用素を反映
        dat[nidx] = app(dat[nidx], ope[nidx], len);
        ope[nidx] = ope_id;
    }

    Data update(int ql, int qr, Operator e, int nidx, int nl, int nr) {
        eval(nidx, nr - nl);
        if (nr <= ql || qr <= nl) return dat[nidx];
        if (ql <= nl && nr <= qr) {
            ope[nidx] = omerge(ope[nidx], e);
            return app(dat[nidx], ope[nidx], nr - nl);
        }
        // 子を再帰的に更新
        Data vl = update(ql, qr, e, nidx * 2, nl, (nl + nr) / 2);
        Data vr = update(ql, qr, e, nidx * 2 + 1, (nl + nr) / 2, nr);
        // 子の更新後から値を更新
        return dat[nidx] = dmerge(vl, vr);
    }

    Data query(int ql, int qr, int nidx, int nl, int nr) {
        eval(nidx, nr - nl);
        if (nr <= ql || qr <= nl) return dat_id;
        if (ql <= nl && nr <= qr) return dat[nidx];
        Data vl = query(ql, qr, nidx * 2, nl, (nl + nr) / 2);
        Data vr = query(ql, qr, nidx * 2 + 1, (nl + nr) / 2, nr);
        return dmerge(vl, vr);
    }

public:
    explicit LazySegmentTree(int N, Data dat_id, Operator ope_id, DataMerger dmerge, OperatorMerger omerge, Applier app)
        : length(1), dat_id(dat_id), ope_id(ope_id), dmerge(dmerge), omerge(omerge), app(app) {
        while (length < N) length *= 2;
        dat.assign(length * 2, dat_id);
        ope.assign(length * 2, ope_id);
    }

    // half-open interval [ql, qr)
    Data update(int ql, int qr, Operator e) { return update(ql, qr, e, 1, 0, length); }

    // half-open interval [ql, qr)
    Data query(int ql, int qr) { return query(ql, qr, 1, 0, length); }
};


int main() {
    int n, m;
    std::cin >> n >> m;
    
    vector<vector<pair<int, Int>>> segs(n + 1);
    for(int i = 0; i < m; ++i) {
        int l, r;
        Int a;
        std::cin >> l >> r >> a;
        segs[r].emplace_back(l, a);
    }

    LazySegmentTree<Int, Int> dp(n + 1, 0, 0,
                                 [](Int a, Int b){return std::max(a, b);},
                                 [](Int e, Int f){return e + f;},
                                 [](Int a, Int e, int k){return a + e;});
    for(int r = 1; r <= n; ++r) {
        dp.update(r, r + 1, dp.query(0, r));
        for(auto p : segs[r]) {
            int l;
            Int a;
            std::tie(l, a) = p;
            dp.update(l, r + 1, a);
        }
    }

    std::cout << dp.query(0, n + 1) << std::endl;
    return 0;
}
