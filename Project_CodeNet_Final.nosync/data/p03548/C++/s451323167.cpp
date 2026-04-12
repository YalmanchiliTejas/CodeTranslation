#include <set>
#include <map>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-9;
const double INF = 2147483647;
#define rep(i, n) rep3(i, 0, n)
#define rep2(i, n) rep3(i, 1, n+1)
#define rep3(i, x, n) for(ll i = x; i < (ll)(n); i++)

template<class T>
void printv(vector<T> v) {
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << ",";
    }
    cout << endl;
}
template<class T>
void printp(vector<pair<T,T>> v) {
    for(auto it = v.begin(); it != v.end(); it++){
        cout << (*it).first << "," << (*it).second << endl;
    }
    cout << endl;
}
template<class T>
void printp(map<T,T> v) {
    for(auto it = v.begin(); it != v.end(); it++){
        cout << (*it).first << "," << (*it).second << endl;
    }
    cout << endl;
}

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数
 
        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
 
        // その結果を push
        res.push_back({a, ex});
    }
 
    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main(void){
    ll x,y,z;
    cin >>x>>y>>z;
    cout << (x-z) / (y+z) << endl;
    
    return 0;
}
