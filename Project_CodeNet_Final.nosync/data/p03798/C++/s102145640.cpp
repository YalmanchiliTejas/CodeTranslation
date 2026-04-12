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
#undef DEBUG

using ll  = long long;
using ull = unsigned long long;

template<typename T>
void print_array(T* p, int n)
{
    REP(i, n) {
        cout << p[i] << " ";
    }
    cout << "\n";
}

int N;
bool S[100000];
bool A1[100000]; // true:正直者, false:嘘つき
bool A2[100000];

bool partner(bool s, bool a_center, bool a_lr)
{
    return s ^ a_center ^ a_lr;
}

bool possible(bool a_ini, bool a_next, bool a_prev)
{
    A1[0] = a_ini;
    A1[1] = a_next;

    FOR(i, 1, N-1) {
        A1[i+1] = partner(S[i], A1[i], A1[i-1]);
    }
    if(A1[N-1] != a_prev) return false;
    if(partner(S[N-1], A1[N-1], A1[N-2]) != A1[0])
        return false;

    return true;

#if 0
    A1[0] = A2[0] = a_ini;

    A1[1]   = a_next;
    A2[N-1] = a_prev;

    FOR(i, 1, N-1) {
        A1[i+1] = partner(S[i], A1[i], A1[i-1]);
    }
    cout << "A1: ";
    print_array(A1, N);
    if(partner(S[N-1], A1[N-1], A1[N-2]) != A1[0])
        return false;

    for(int i = N-1; i >= 2; --i) {
        A2[i-1] = partner(S[i], A2[i], A2[i+1]);
    }
    cout << "A2: ";
    print_array(A2, N);
    if(partner(S[1], A2[1], A2[2]) != A2[0])
        return false;

    return equal(A1, A1+N, A2);
#endif
}

void solve()
{
    bool ok = false;
    if(S[0]) {
        if(possible(true, true, true)) {
            ok = true;
            goto finish;
        }
        if(possible(true, false, false)) {
            ok = true;
            goto finish;
        }
        if(possible(false, true, false)) {
            ok = true;
            goto finish;
        }
        if(possible(false, false, true)) {
            ok = true;
            goto finish;
        }
    }
    else {
        if(possible(true, true, false)) {
            ok = true;
            goto finish;
        }
        if(possible(true, false, true)) {
            ok = true;
            goto finish;
        }
        if(possible(false, true, true)) {
            ok = true;
            goto finish;
        }
        if(possible(false, false, false)) {
            ok = true;
            goto finish;
        }
    }

finish:
    if(!ok) {
        cout << -1 << "\n";
    }
    else {
        REP(i, N) {
            cout << (A1[i] ? 'S' : 'W');
        }
        cout << "\n";
    }
}

int main()
{
    cin >> N;
    string s;
    cin >> s;
    REP(i, N) {
        S[i] = s[i] == 'o';
    }

    solve();

    return 0;
}
