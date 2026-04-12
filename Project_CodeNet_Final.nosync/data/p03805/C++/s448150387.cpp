#include <iostream>
#include <vector>
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<Int>;
using VVI = vector<vector<Int> >;

int in_rec(VVI& v, int n, int target, VI check_table) {
    //cout << target << endl;
    Int ret = 0;
    Int size = v[target].size();
    check_table[target] = 1;
    bool filled = true;
    for (Int i = 0; i < n; ++i) {
        if (check_table[i] == 0) {
            filled = false;
        }
    }
    if (filled == true) {
        ret += 1;
    }

    for (Int i = 0; i < size; ++i) {
        if (check_table[v[target][i]] == 0) {
            ret += in_rec(v, n, v[target][i], check_table);
        }
    }

    //cout << target << " " << ret << endl;
    return ret;
}

int rec(VVI& v, int n) {
    Int ret = 0;
    VI table(n, 0);
    Int i = 0;
    ret += in_rec(v, n, i, table);
    return ret;
}

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
    cout << rec(v, n) << endl;
    return 0;
}
