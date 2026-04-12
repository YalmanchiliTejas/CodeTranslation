#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

typedef unsigned long long ull; // FUCK
#define int ull
#define ll ull

const int MX = 505;
const int BIT = 64;

ull ONE = 1;

int n;
ull ans[MX][MX];
int s[MX];
int t[MX];
ull u[MX];
ull v[MX];
int pos[MX];

ll getBit(ull a, ull num) {
        return ((a & (ONE << num)) != 0);
}

void read() {
        cin >> n;
        for (int i = 0; i < n; ++i) {
                cin >> s[i];
        }
        for (int i = 0; i < n; ++i) {
                cin >> t[i];
        }
        for (int i = 0; i < n; ++i) {
                cin >> u[i];
        }
        for (int i = 0; i < n; ++i) {
                cin >> v[i];
        }


}

int check(vector<vector<ll>> &ans) {
        for (int i = 0; i < n; ++i) {
                ll value = 0;
                if (s[i] == 0) {
                        value = ans[i][0];
                        for (int j = 1; j < n; ++j)
                                value &= ans[i][j];
                } else {
                        value = 0;
                        for (int j = 0; j < n; ++j)
                                value |= ans[i][j];
                }
                if (value != u[i]) return 0;
        }

        for (int j = 0; j < n; ++j) {
                ll value = 0;
                if (t[j] == 0) {
                        value = ans[0][j];
                        for (int i = 1; i < n; ++i)
                                value &= ans[i][j];
                } else {
                        value = 0;
                        for (int i = 0; i < n; ++i)
                                value |= ans[i][j];
                }
                if (value != v[j]) return 0;
        }
        return 1;
}

pair<ll, vector<vector<ll>>> stupid() {
        vector<vector<ll>> ans(n, vector<ll>(n));

        for (int mask = 0; mask < (1 << (n * n)); ++mask) {
                int num = 0;
                for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < n; ++j) {
                                ans[i][j] = getBit(mask, num);
                                num++;
                        }
                }
                if (check(ans)) {
                        return make_pair(1, ans);
                }
        }

        return make_pair(0, ans);
}

pair<int, vector<vector<ll>>> smart() {
        vector<vector<ll>> ans(n, vector<ll>(n));

        for (int i = 0; i < n; ++i) {
                int head = 0;
                for (int j = 0; j < BIT; ++j)
                        if (getBit(u[i], j))
                                pos[head++] = j;
                if (s[i] == 0) {
                        for (int j = 0; j < n; ++j)
                                for (int k = 0; k < head; ++k)
                                        ans[i][j] |= (ONE << pos[k]);
                } else {
                        for (int j = 0; j < n; ++j) {
                                for (int k = 0; k < head; ++k) {
                                        if (t[j] == 1 && getBit(v[j], pos[k])) {
                                                ans[i][j] |= (ONE << pos[k]);
                                        }
                                }
                        }
                }
        }

        for (int j = 0; j < n; ++j) {
                int head = 0;
                for (int i = 0; i < BIT; ++i) {
                        if (getBit(v[j], i))
                                pos[head++] = i;
                }
                if (t[j] == 0) {
                        for (int i = 0; i < n; ++i)
                                for (int k = 0; k < head; ++k)
                                        ans[i][j] |= (ONE << pos[k]);
                } else {
                        for (int i = 0; i < n; ++i) {
                                for (int k = 0; k < head; ++k) {
                                        if (s[i] == 1 && getBit(u[i], pos[k]))
                                                ans[i][j] |= (ONE << pos[k]);
                                }
                        }
                }
        }

        for (int i = 0; i < n; ++i) {
                if (!s[i]) continue;
                ll yet = 0;
                for (int j = 0; j < n; ++j)
                        yet |= ans[i][j];
                ll mask = 0;
                for (int j = 0; j < BIT; ++j) {
                        ll A = getBit(u[i], j);
                        ll B = getBit(yet, j);
                        if (B == 1 && A == 0) return make_pair(0, ans);
                        if (B == 0 && A == 1) {
                                bool ok = 0;
                                for (int k = 0; k < n; ++k) {
                                        if (t[k]) continue;
                                        ans[i][k] |= (ONE << j);
                                        ll AND = ans[0][k];
                                        for (int f = 1; f < n; ++f)
                                                AND &= ans[f][k];
                                        if (AND == v[k]) {
                                                ok = 1;
                                                break;
                                        }
                                        ans[i][k] ^= (ONE << j);
                                }
                                if (!ok) return make_pair(0, ans);
                        }
                }
        }

        for (int j = 0; j < n; ++j) {
                if (!t[j]) continue;
                ll yet = 0;
                for (int i = 0; i < n; ++i)
                        yet |= ans[i][j];
                ll mask = 0;
                for (int i = 0; i < BIT; ++i) {
                        ll A = getBit(v[j], i);
                        ll B = getBit(yet, i);
                        if (B == 1 && A == 0) return make_pair(0, ans);
                        if (B == 0 && A == 1) {
                                bool ok = 0;
                                for (int k = 0; k < n; ++k) {
                                        if (s[k]) continue;
                                        ans[k][j] |= (ONE << i);
                                        ll AND = ans[k][0];
                                        for (int f = 1; f < n; ++f)
                                                AND &= ans[k][f];
                                        if (AND == u[k]) {
                                                ok = 1;
                                                break;
                                        } 
                                        ans[k][j] ^= (ONE << i);
                                }
                                if (!ok) return make_pair(0, ans);
                        }
                }
        }

        return make_pair(check(ans), ans);
}

void print() {
        cout << n << "\n";
        for (int i = 0; i < n; ++i)
                cout << s[i] << " ";
        cout << "\n";
        for (int i = 0; i < n; ++i)
                cout << t[i] << " ";
        cout << "\n";
        for (int i = 0; i < n; ++i)
                cout << u[i] << " ";
        cout << "\n";
        for (int i = 0; i < n; ++i)
                cout << v[i] << " ";
        cout << "\n";
}

signed main() {
        cin.sync_with_stdio(0);

        /*
        for (int mask = 0; mask < (1 << 16); ++mask) {
                n = 4;
                int num = 0;
                for (int i = 0; i < n; ++i)
                        s[i] = getBit(mask, num++);
                for (int i = 0; i < n; ++i)
                        t[i] = getBit(mask, num++);
                for (int i = 0; i < n; ++i)
                        u[i] = getBit(mask, num++);
                for (int i = 0; i < n; ++i)
                        v[i] = getBit(mask, num++);
                
                auto s1 = stupid();
                auto s2 = smart();
                if (s1.first != s2.first) {
                        print();

                        for (int i = 0; i < n; ++i)
                                for (int j = 0; j < n; ++j)
                                        cout << s1.second[i][j] << " \n"[j == 2];

                        return 0;
                }
        }*/


        read();
        auto solve = smart();
        if (solve.first == 0) {
                cout << -1;
        } else {
                for (int i = 0; i < n; ++i)
                        for (int j = 0; j < n; ++j)
                                cout << solve.second[i][j] << " \n"[j == n - 1];
        }
        

        return 0;
}