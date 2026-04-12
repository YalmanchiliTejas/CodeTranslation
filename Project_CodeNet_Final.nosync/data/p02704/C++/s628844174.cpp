#include <iostream>
#include <vector>
#include <utility>
using i64 = long long;
using u64 = unsigned long long;

[[noreturn]]
void no() {
    std::cout << -1 << std::endl;
    exit(0);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<u64> s(n), t(n), u(n), v(n);
    for (auto &e : s) std::cin >> e;
    for (auto &e : t) std::cin >> e;
    for (auto &e : u) std::cin >> e;
    for (auto &e : v) std::cin >> e;

    std::vector ret(n, std::vector<u64>(n));
    for (u64 i = 0; i < 64; i++) {
        const u64 base = 1ull << i;
        std::vector<int> row(n), col(n), rr(n), rc(n);
        std::vector<std::pair<int, int>> q;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            const int r = !s[i], k = (base & u[i]) > 0,
                    c = !t[j], l = (base & v[j]) > 0;
            if (r) {
                if (k) {
                    // row AND 1
                    if (c == 0 && l == 0) no();
                    ret[i][j] |= base;
                    row[i] |= 2;
                    col[j] |= 2;
                } else {
                    // row AND 0
                    if (c == 0 && l) {
                        q.emplace_back(i, j);
                        rr[i]++;
                        rc[j]++;
                    } else if (c && l) {
                        ret[i][j] |= base;
                        row[i] |= 2;
                        col[j] |= 2;
                    } else {
                        row[i] |= 1;
                        col[j] |= 1;
                    }
                }
            } else {
                if (k) {
                    // row OR 1
                    if (c && l == 0) {
                        q.emplace_back(i, j);
                        rr[i]++;
                        rc[j]++;
                    } else if (c || l) {
                        ret[i][j] |= base;
                        row[i] |= 2;
                        col[j] |= 2;
                    } else {
                        row[i] |= 1;
                        col[j] |= 1;
                    }
                } else {
                    // row OR 0
                    if (c && l) no();
                    row[i] |= 1;
                    col[j] |= 1;
                }
            }
        }

        for (const auto [i, j] : q) {
            const int r = !s[i];
            rr[i]--;
            rc[j]--;
            if (r) {
                // row AND 0, col OR 1
                const bool r0 = row[i] & 1, c1 = col[j] & 2;
                if (r0) {
                    ret[i][j] |= base;
                    row[i] |= 2;
                    col[j] |= 2;
                } else if (c1) {
                    row[i] |= 1;
                    col[j] |= 1;
                } else if (rr[i]) {
                    ret[i][j] |= base;
                    row[i] |= 2;
                    col[j] |= 2;
                } else if (rc[j]) {
                    row[i] |= 1;
                    col[j] |= 1;
                } else {
                    no();
                }
            } else {
                // row OR 1, col AND 0
                const bool r1 = row[i] & 2, c0 = col[j] & 1;
                if (r1) {
                    row[i] |= 1;
                    col[j] |= 1;
                } else if (c0) {
                    ret[i][j] |= base;
                    row[i] |= 2;
                    col[j] |= 2;
                } else if (rr[i]) {
                    row[i] |= 1;
                    col[j] |= 1;
                } else if (rc[j]) {
                    ret[i][j] |= base;
                    row[i] |= 2;
                    col[j] |= 2;
                } else {
                    no();
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!s[i]) {
            u64 k = -1;
            for (int j = 0; j < n; j++) k &= ret[i][j];
            if (k != u[i]) no();
        } else {
            u64 k = 0;
            for (int j = 0; j < n; j++) k |= ret[i][j];
            if (k != u[i]) no();
        }
    }

    for (int i = 0; i < n; i++) {
        if (!t[i]) {
            u64 k = -1;
            for (int j = 0; j < n; j++) k &= ret[j][i];
            if (k != v[i]) no();
        } else {
            u64 k = 0;
            for (int j = 0; j < n; j++) k |= ret[j][i];
            if (k != v[i]) no();
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) std::cout << ret[i][j] << ' ';
        std::cout << '\n';
    }

    return 0;
}
