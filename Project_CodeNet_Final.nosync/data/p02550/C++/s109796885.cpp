#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <fstream>
#include <iterator>
#include <random>
#include <chrono>


#define forr(i,start,count) for (int i = (start); i < (start)+(count); ++i)
#define set_map_includes(set, elt) (set.find((elt)) != set.end())
#define readint(i) int i; cin >> i
#define readll(i) ll i; cin >> i
#define readdouble(i) double i; cin >> i
#define readstring(s) string s; cin >> s

typedef long long ll;

using namespace std;

ll modd = 1000 * 1000 * 1000 + 7;

int main()   {

      ios_base::sync_with_stdio(false);

      cout.precision(17);
      mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
      uniform_int_distribution<int> rand_gen(0, modd);   // rand_gen(rng) gets the rand no


//    readint(test_cases);
    int test_cases = 1;
    forr(t, 1, test_cases) {
        readll(n);
        readll(x);
        readll(m);

        if (n<=100100) {
            ll ret = 0, a = x;
            forr(i,0,n) {
                ret += x;
                x *= x; x %= m;
            }
            cout << ret << endl;
            continue;
        }

        vector<int> which(m,-1);
        ll curr = x;
        int i = 1;
        while (true) {
            which[curr] = i;
            ++i;
            curr *= curr; curr %= m;
            if (which[curr]!=-1) {break;}
        }

        ll ret = 0;
        ll a = x;
        forr(j,0,which[curr]-1) {
            ret += a;
            a *= a; a %= m;
        }
        n -= (which[curr]-1);
        ll cycle_sum = 0;
        ll cycle_count = i - which[curr];
        forr(j,0,cycle_count) {
            cycle_sum += a;
            a *= a; a %= m;
        }
        ll no_cycles = n/cycle_count;
        ret += no_cycles * cycle_sum;
        n %= cycle_count;
        forr(j,0,n) {
            ret += a;
            a *= a; a %= m;
        }
        cout << ret << endl;

    }
    return 0;
}
