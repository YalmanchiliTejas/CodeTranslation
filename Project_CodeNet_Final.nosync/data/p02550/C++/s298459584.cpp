#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint n, x, m;
const lint E = 40;

lint f(lint z) {
    return z * z % m;
}

struct str {
    lint dest;
    lint sum;
    str() {}
    str(lint d, lint s) : dest(d), sum(s) {}
};

vector<vector<str>> doubling;

lint solve(int start, lint num) {
    lint now = start;
    bitset<E> b(num);
    lint res = 0;
    for (int i = 0; i < E; i++) {
        if (b[i]) {
            auto s = doubling[i][now];
            now = s.dest;
            res += s.sum;
        }
    }
    return res;
}

int main() {
    cin >> n >> x >> m;
    doubling.resize(E, vector<str>(m));
    for (int i = 0; i < m; i++) {
        doubling[0][i] = str(f(i), i);
    }
    for (int e = 1; e < E; e++) {
        for (int i = 0; i < m; i++) {
            auto first = doubling[e - 1][i];
            auto second = doubling[e - 1][first.dest];
            doubling[e][i] = str(second.dest, first.sum + second.sum);
        }
    }
    cout << solve(x, n) << endl;
}