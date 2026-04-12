
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

ll modd = 1000*1000*1000+7;

template<class T>
T fastpower(T a, long long n) {  // n must be >= 1
  if (n % 2 == 0) {  
      T halfpower = fastpower<T>(a, n/2);
      return (halfpower*halfpower) % modd;
  } else {
      if (n == 1) {  return a; } else {  
          T halfpower = fastpower<T>(a, n/2);
          return (((halfpower*halfpower)%modd)*a)%modd;
      }
  }
};


int main()   {

    ios_base::sync_with_stdio(false);

    cout.precision(17);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> rand_gen(0, modd);   // rand_gen(rng) gets the rand no

//    auto start = chrono::steady_clock::now()

//    readint(test_cases);
    int test_cases = 1;
    forr(t, 1, test_cases) {
        readint(n);
        ll summ = 0, summ_sq = 0;
        forr(i,0,n) {
            readll(aa);
            summ += aa; summ %= modd;
            summ_sq += (aa*aa) % modd; summ_sq %= modd;
        }
        ll ret = (summ*summ) % modd;
        ret += (modd - summ_sq); ret %= modd;
        ret *= fastpower<ll>(2, modd-2); ret %= modd;

        cout << ret << endl;
    }

//    auto end = chrono::steady_clock::now();
//    cerr << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;

    return 0;
}