

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
#include <math.h>
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

long long gcd(long long a, long long b) { 
    if (a == 0)  {   return b;  }
    return gcd(b % a, a); 
};

int main()   {
    cout.precision(17);
    ll modd = 1000 * 1000 * 1000 + 7;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> rand_gen(0, modd);   // rand_gen(rng) gets the rand no
    ll infinit = 10000000000000000;


//    readint(test_cases);
    int test_cases = 1;
    forr(t, 1, test_cases) {
        readll(n);
        vector<ll> a;
        forr(i,0,n) {
            readint(kk); a.push_back(kk);
        }
        vector<ll> part_sum_even; part_sum_even.push_back(0);
        vector<ll> part_sum_odd; part_sum_odd.push_back(0);

        forr(i,0,a.size()) {
            ll ev = 0, od = 0;
            if (i%2==0) {ev=a[i];} else {od=a[i];}
            part_sum_even.push_back(part_sum_even.back() + ev);
            part_sum_odd.push_back(part_sum_odd.back() + od);
        }
        
        ll ret;
        if (n%2!=0) {
            ret = part_sum_odd.back();
            for(int i = 0; i < n-1; i+=2) {
                ret = max(ret, part_sum_even[i+1] + part_sum_odd.back() - part_sum_odd[i+3]);
            }
            for (int i = 1; i < n-2; i+=2) {
                ret = max(ret, part_sum_odd[i+1] + part_sum_even.back() - part_sum_even[i+3]);
            }
            ll min_total = a[0], min_local = a[0];
            for(int i = 2; i < n; i+=2) {
                min_local = min(a[i], a[i]-a[i-1]+min_local);
                min_total = min(min_total, min_local);
            }
            ret = max(ret, part_sum_even.back() - min_total);
        } else {
            ret = max(part_sum_even.back(), part_sum_odd.back());
            for(int i = 0; i < n-2; i+=2) {
                ret = max(ret, part_sum_even[i+1] + part_sum_odd.back() - part_sum_odd[i+3]);
            }
        }
        
        cout << ret << endl;
    }
    return 0;
}
