#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


class FenwickTree {
    public:
        FenwickTree(int n) : N(n), data(n, 0) {

        }

        void put(int x, long long v) {
            for (; x < N; x |= x + 1) {
                data[x] += v;
            }
        }

        long long get(int x) {
            long long res = 0;
            for (; x >= 0; x = (x & (x + 1)) - 1) {
                res += data[x];
            }
            return res;
        }

        int kthElement(long long K) {
            int res = 0;
            int h = 0;
            while (1 << (h + 1) <= N) {
                ++h;
            }

            for (int i = h; i >= 0; --i) {
                if (res + (1 << i) > N) {
                    continue;
                }
                if (data[res + (1 << i) - 1] < K) {
                    K -= data[res + (1 << i) - 1];
                    res |= 1 << i;
                }
            }

            return res;
        }

    private:
        int N;
        vector<long long> data;
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<int> X(A);
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    auto index = [&](int x) {
        auto it = lower_bound(X.begin(), X.end(), x);
        assert(*it == x);
        return it - X.begin();
    };

    for (auto& x : A) {
        x = index(x);
    }

    FenwickTree ft(n);

    for (int i = 1; i < n; ++i) {
        ft.put(A[i], 1);
    }

    int K = (n - 1) / 2 + 1;
    cout << X[ft.kthElement(K)] << '\n';

    for (int i = 1; i < n; ++i) {
        ft.put(A[i - 1], 1);
        ft.put(A[i], -1);
        cout << X[ft.kthElement(K)] << '\n';
    }

    return 0;
}