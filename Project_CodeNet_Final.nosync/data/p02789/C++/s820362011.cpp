#include <algorithm>
#include <bitset>
#include <boost/multiprecision/cpp_int.hpp>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <numeric>
#include <sstream>
#include <stdio.h>
#include <string>
#include <tuple>
#include <vector>
#include<iomanip>
namespace mp = boost::multiprecision;
using namespace std;
using ull = unsigned long long;
using ld = long double;
using lll = boost::multiprecision::cpp_int;
using ll = long long;
#define FOR(i, N) for(ll i = 0; i < N; ++i)

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
// using int = ll;
ll gcd(ll m, ll n) {
    if(n == 0)
        return abs(m);
    return (gcd(n, m % n));
}
void putYN(bool b) {
    if(b) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
ll combi(ll n, ll k) {
    ll r = 1, rr = 1;
    for(ll i = 0; i < k; ++i) {
        r *= (n - i);
        rr *= (i + 1);
        // r %= 1000000007;
        // rr %= 1000000007;
    }
    r /= rr;
    // r %= 1000000007;
    return r;
}
int main(){
  ll N,M;
  cin>>N>>M;
  putYN(N==M);
  return 0;
}
