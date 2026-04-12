#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <tuple>
using namespace std;
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long ll;
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;

int used[100010];

int main ()
{
    ll N,X,M;
    cin >> N >> X >> M;

    ll A = X;
    map<ll,ll> table;
    for (int i = 0; i < N; i++) {
        if (used[A] == 2) {
            N = N - i;
            break;
        }
        used[A]++;
        if (used[A] == 2) {
            table[table.size()] = A;
        }

        A = (A * A) % M;

        if (i == N - 1) {
            ll ans = 0;
            REP(j,100010) {
                ans += used[j] * j;
            }
            cout << ans << endl;
            return 0;
        }
    }

    ll sum = 0;
    ll ans_a = 0;
    REP(i,100010) {
        if (used[i] == 2) {
            sum += i;
        }
        ans_a += used[i] * i;
    }

    ll ans = (N / (ll)table.size()) * sum + ans_a;
    N = N - ((N / (ll)table.size()) * (ll)table.size());

    for (int i = 0; i < N; i++) {
        ans += table[i];
    }

    cout << ans << endl;

    return 0;
}
