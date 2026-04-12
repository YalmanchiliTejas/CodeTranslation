#include <algorithm>
#include <bitset>
//#include <boost/multiprecision/cpp_int.hpp>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <sstream>
#include <stdio.h>
#include <string>
#include <tuple>
#include <vector>
//namespace mp = boost::multiprecision;
using namespace std;
using ull = unsigned long long;
using ld = long double;
// using ll = boost::multiprecision::cpp_int;
using ll = long long;
#define FORi(N) for(ll i = 0; i < N; ++i)
#define FORj(N) for(ll j = 0; j < N; ++j)
#define FORk(N) for(ll k = 0; k < N; ++k)

#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
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
void swap(ll &a, ll &b) {
    ll tmp = a;
    a = b;
    b = tmp;
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

int main() {
    ll N;
    cin >> N;
    vector<ll> A;
    FORi(N) {
        ll tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
    vector<ll> aa;
    FORi(N){
        ll f = false;
        auto it = lower_bound(ALL(aa),A[i]);
        if(it==aa.begin()){
            //新しく加える
            aa.insert(it,A[i]);
        }else{
            auto it2 = lower_bound(ALL(aa), A[i]);
            it2--;
            *it2 = A[i];
        }
        /*if(!f){
            aa.push_back(A[i]);
        }*/
    }
    //FORi(aa.size()) { cout << aa[i] << endl; }
    cout << aa.size() << endl;
    return 0;
}