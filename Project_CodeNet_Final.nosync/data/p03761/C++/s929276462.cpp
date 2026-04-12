#include <array>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <tuple>
#include <utility>
#include <limits>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdint>
#include <cassert>

using namespace std;

template<typename T, size_t N>
constexpr size_t NELEMS(T (&)[N]) { return N; }

#define FOR(i, start, end) for(int i = (start); i < (end); ++i)
#define REP(i, n) FOR(i, 0, n)

#define DEBUG
//#undef DEBUG

int N;
string S[50];

int bin[26];

void solve()
{
    fill(begin(bin), end(bin), 99999);

    REP(i, N) {
        int cnt[26] = {};
        for(char c : S[i]) {
            ++cnt[c-'a'];
        }
        REP(j, 26) {
            bin[j] = min(bin[j], cnt[j]);
        }
    }

    string ans;
    REP(i, 26) {
        ans.append(bin[i], i+'a');
    }

    cout << ans << "\n";
}

int main()
{
    cin >> N;
    REP(i, N) {
        cin >> S[i];
        //cout << S[i] << "\n";
    }

    solve();

    return 0;
}
