#include <iostream>
#include <vector>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N; cin >> N;
    vector<long long> s(N);
    for (int i = 0; i < N; ++i) cin >> s[i];

    long long res = 0;
    for (int p = 1; p <= N-1; ++p) {
        if ((N-1) % p == 0) {
            long long tmp = 0;
            long long cur = 0;
            int i = 0, j = N-1;
            for (; i < j; i += p, j -= p) {
                cur += s[i] + s[j];
                chmax(tmp, cur);
            }
            chmax(res, tmp);
        }
        else {
            long long tmp = 0;
            long long cur = 0;
            int i = 0, j = N-1;
            for (; i < N-1 && j > p; i += p, j -= p) {
                cur += s[i] + s[j];
                chmax(tmp, cur);
            }
            chmax(res, tmp);
        }
    }
    cout << res << endl;
}
