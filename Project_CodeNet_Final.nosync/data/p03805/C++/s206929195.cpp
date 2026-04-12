#include <iostream>
#include <vector>
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<Int>;
using VVI = vector<vector<Int> >;

// 隣接リスト
class DepthFirstSearch {
    public:
    // 探索のデフォルト始点
    const static UInt DEFAULT_START_NODE_NUMBER = 0;
    // 入力: 隣接リスト
    // 出力: ハミルトンパスの個数
    static UInt HamiltonianPathNumber(VVI& adjacency_list) {
        VI dst_table(adjacency_list.size(), 0); // ノードを探索したかどうかをチェックするテーブル
        return InnerHamiltonianPathNumber(adjacency_list, dst_table, DEFAULT_START_NODE_NUMBER);
    }
    private:
    static UInt InnerHamiltonianPathNumber(VVI& adjacency_list, VI dst_table, UInt node_number) {
        // dst_tableを値渡しにする事で，再起する前の頂点の到達状況を保持することができる．
        // これにより，再起による到達の影響を受けない．
        UInt ret = 0;
        dst_table[node_number] = 1;
        bool all_filled = true;
        for (UInt i = 0; i < adjacency_list.size(); ++i) {
            if (dst_table[i] == 0) {
                all_filled = false;
            }
        }
        if (all_filled == true) {
            ret += 1;
        }
        for (UInt i = 0; i < adjacency_list[node_number].size(); ++i) {
            if (dst_table[adjacency_list[node_number][i]] == 0) {
                ret += InnerHamiltonianPathNumber(adjacency_list, dst_table, adjacency_list[node_number][i]);
            }
        }
        return ret;
    }
};

int main(void) {
    Int n, m;
    cin >> n >> m;
    VVI v(n);
    Int s, t;
    for (Int i = 0; i < m; ++i) {
        cin >> s >> t;
        --s;--t;
        v[s].push_back(t);
        v[t].push_back(s);
    }
    cout << DepthFirstSearch::HamiltonianPathNumber(v) << endl;
    return 0;
}
