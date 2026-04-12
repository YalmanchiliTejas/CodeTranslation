#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <sstream>

#include <array>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>

#include <algorithm>
#include <numeric>

#include <cstdint>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>
#include <chrono>
#include <climits>
#include <fstream>
#include <ios>

#include <iterator>
#include <utility>
#include <complex>
#include <memory>


using namespace std;

//#define MY_DEBUG

#define DESYNC_IO


#ifdef MY_DEBUG
#define DEBUG_STDERR(x) cerr << x << endl;
#else
#define DEBUG_STDERR(x)
#endif // MY_DEBUG

void Solve() {
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(begin(v), end(v));
    int i{ 0 };
    int j{ n - 1 };
    long long sum_start_with_max{ 0 };
    long long left{ v[j] };
    long long right{ v[j] };
    --j;
    while (i <= j) {
        if (j == i) {
            if (abs(v[j] - left) > abs(v[j] - right)) {
                sum_start_with_max += abs(v[j] - left);
            } else {
                sum_start_with_max += abs(v[j] - right);
            }
            break;
        } else {
            if (abs(v[i] - left) + abs(v[i + 1] - right) > abs(v[i + 1] - left) + abs(v[i] - right)) {
                sum_start_with_max += abs(v[i] - left) + abs(v[i + 1] - right);
                left = v[i];
                right = v[i + 1];
            } else {
                sum_start_with_max += abs(v[i] - right) + abs(v[i + 1] - left);
                left = v[i + 1];
                right = v[i];
            }
            i += 2;
        }
        if (i > j) {
            break;
        }
        if (j == i) {
            if (abs(v[j] - left) > abs(v[j] - right)) {
                sum_start_with_max += abs(v[j] - left);
            } else {
                sum_start_with_max += abs(v[j] - right);
            }
            break;
        } else {
            if (abs(v[j] - left) + abs(v[j - 1] - right) > abs(v[j - 1] - left) + abs(v[j] - right)) {
                sum_start_with_max += abs(v[j] - left) + abs(v[j - 1] - right);
                left = v[j];
                right = v[j - 1];
            } else {
                sum_start_with_max += abs(v[j] - right) + abs(v[j - 1] - left);
                left = v[j - 1];
                right = v[j];
            }
            j -= 2;
        }
    }
    i = 0;
    j = n - 1;
    long long sum_start_with_min{ 0 };
    left = v[i];
    right = v[i];
    ++i;
    while (i <= j) {
        if (j == i) {
            if (abs(v[j] - left) > abs(v[j] - right)) {
                sum_start_with_min += abs(v[j] - left);
            } else {
                sum_start_with_min += abs(v[j] - right);
            }
            break;
        } else {
            if (abs(v[j] - left) + abs(v[j - 1] - right) > abs(v[j - 1] - left) + abs(v[j] - right)) {
                sum_start_with_min += abs(v[j] - left) + abs(v[j - 1] - right);
                left = v[j];
                right = v[j - 1];
            } else {
                sum_start_with_min += abs(v[j] - right) + abs(v[j - 1] - left);
                left = v[j - 1];
                right = v[j];
            }
            j -= 2;
        }
        if (i > j) {
            break;
        }
        if (j == i) {
            if (abs(v[j] - left) > abs(v[j] - right)) {
                sum_start_with_min += abs(v[j] - left);
            } else {
                sum_start_with_min += abs(v[j] - right);
            }
            break;
        } else {
            if (abs(v[i] - left) + abs(v[i + 1] - right) > abs(v[i + 1] - left) + abs(v[i] - right)) {
                sum_start_with_min += abs(v[i] - left) + abs(v[i + 1] - right);
                left = v[i];
                right = v[i + 1];
            } else {
                sum_start_with_min += abs(v[i] - right) + abs(v[i + 1] - left);
                left = v[i + 1];
                right = v[i];
            }
            i += 2;
        }
    }
    cout << max(sum_start_with_max, sum_start_with_min);
}

void Run() {
#ifdef MY_DEBUG
    chrono::high_resolution_clock::time_point start{ chrono::high_resolution_clock::now() };
#endif // MY_DEBUG

#ifdef DESYNC_IO
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DESYNC_IO

#ifdef MY_DEBUG
    ifstream input{ "input.txt" };
    cin.rdbuf(input.rdbuf());
#endif // MY_DEBUG

    Solve();

#ifdef MY_DEBUG
    auto dt{ std::chrono::high_resolution_clock::now() - start };
    auto dt_millisec{ std::chrono::duration_cast<std::chrono::milliseconds>(dt) };
#endif // MY_DEBUG
    DEBUG_STDERR("\ntime spent: " << dt_millisec.count() << " miilliseconds");
}

int main() {
    Run();
    return 0;
}