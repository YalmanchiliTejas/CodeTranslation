#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int64_t N, X, M;
    cin >> N >> X >> M;
    vector<int64_t> values(M + 5);
    vector<int64_t> seen(M, -1);
    int64_t a = X;
    values[0] = a;
    seen[a] = 0;
    int64_t total = a;

    for (int64_t i = 1; i < N; i++) {
        a = a * a % M;
        values[i] = a;

        if (seen[a] >= 0) {
            int64_t start = seen[a];
            int64_t len = i - start;

            for (int64_t j = start; j < i; j++) {
                int64_t occur = (N - j + len - 1) / len - 1;
                total += occur * values[j];
            }

            break;
        }

        seen[a] = i;
        total += a;
    }

    cout << total << '\n';
}
