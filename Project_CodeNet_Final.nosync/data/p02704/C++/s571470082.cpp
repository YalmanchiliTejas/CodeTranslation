#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int BITS = 64;

int N;
vector<vector<uint64_t>> solution;
vector<int> row_type, col_type;

bool solve(int bit, vector<int> row_bit, vector<int> col_bit) {
    vector<vector<int>> answer(N, vector<int>(N, -1));
    vector<int> rows, cols;
    int which = -1;

    for (int r = 0; r < N; r++)
        if (row_type[r] != row_bit[r]) {
            which = row_bit[r];
            int other = 1 - which;

            for (int c = 0; c < N; c++) {
                if (answer[r][c] == other)
                    return false;

                answer[r][c] = which;
            }
        } else {
            rows.push_back(r);
        }

    for (int c = 0; c < N; c++)
        if (col_type[c] != col_bit[c]) {
            which = col_bit[c];
            int other = 1 - which;

            for (int r = 0; r < N; r++) {
                if (answer[r][c] == other)
                    return false;

                answer[r][c] = which;
            }
        } else {
            cols.push_back(c);
        }

    int R = int(rows.size());
    int C = int(cols.size());

    if (R < N && C < N) {
        for (int r : rows)
            for (int c : cols)
                answer[r][c] = 1 - which;

        for (int r = 0; r < N; r++)
            for (int c = 0; c < N; c++)
                solution[r][c] |= uint64_t(bool(answer[r][c])) << bit;

        return true;
    }

    if (R * C > 0) {
        if (R < C) {
            for (int ci = 0; ci < C; ci++) {
                int ri = ci % R;
                int c = cols[ci];
                int r = rows[ri];

                if (col_bit[c] != which)
                    answer[r][c] = col_bit[c];
            }

            for (int r = 0; r < N; r++)
                for (int c = 0; c < N; c++)
                    if (answer[r][c] < 0)
                        answer[r][c] = row_bit[r];
        } else {
            for (int ri = 0; ri < R; ri++) {
                int ci = ri % C;
                int r = rows[ri];
                int c = cols[ci];

                if (row_bit[r] != which)
                    answer[r][c] = row_bit[r];
            }

            for (int r = 0; r < N; r++)
                for (int c = 0; c < N; c++)
                    if (answer[r][c] < 0)
                        answer[r][c] = col_bit[c];
        }
    }

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            solution[r][c] |= uint64_t(bool(answer[r][c])) << bit;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N;
    row_type.resize(N);
    col_type.resize(N);
    vector<uint64_t> row_val(N), col_val(N);

    for (auto &s : row_type)
        cin >> s;

    for (auto &t : col_type)
        cin >> t;

    for (auto &u : row_val)
        cin >> u;

    for (auto &v : col_val)
        cin >> v;

    auto &&fail = []() {
        cout << -1 << '\n';
        exit(0);
    };

    solution.assign(N, vector<uint64_t>(N, 0));

    for (int bit = 0; bit < BITS; bit++) {
        vector<int> row_bit(N), col_bit(N);

        for (int i = 0; i < N; i++) {
            row_bit[i] = int(row_val[i] >> bit & 1);
            col_bit[i] = int(col_val[i] >> bit & 1);
        }

        if (!solve(bit, row_bit, col_bit))
            fail();
    }

    bool valid = true;

    for (int r = 0; r < N; r++)
        if (row_type[r] == 0) {
            uint64_t value = numeric_limits<uint64_t>::max();

            for (int c = 0; c < N; c++)
                value &= solution[r][c];

            if (value != row_val[r])
                valid = false;
        } else {
            uint64_t value = 0;

            for (int c = 0; c < N; c++)
                value |= solution[r][c];

            if (value != row_val[r])
                valid = false;
        }

    for (int c = 0; c < N; c++)
        if (col_type[c] == 0) {
            uint64_t value = numeric_limits<uint64_t>::max();

            for (int r = 0; r < N; r++)
                value &= solution[r][c];

            if (value != col_val[c])
                valid = false;
        } else {
            uint64_t value = 0;

            for (int r = 0; r < N; r++)
                value |= solution[r][c];

            if (value != col_val[c])
                valid = false;
        }

    dbg(solution);

    if (!valid)
        fail();

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cout << solution[i][j] << (j < N - 1 ? ' ' : '\n');
}
