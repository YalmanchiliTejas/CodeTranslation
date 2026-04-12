#include <set>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <vector>
#include <tuple>
#include <string>
#include <math.h>
#include <time.h>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <limits>
#include <climits>
#include <numeric>

#define lnd '\n'
// #define reverse(i, n) for(ll i = n-1; i >= 0; --i)
#define from(i, n) for (ll i = 0; i < n; ++i)
#define REPN(i, n) for (ll i = 1; i <= n; ++i)
#define ALL(s) (s).begin(), (s).end()
#define rALL(s) (s).rbegin(), (s).rend()
#define sz(s) (int)(s).size()
#define mk make_pair
#define pb push_back
#define sqr(s) ((s) * (s))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;


void solution();

template <class T>
T GCD (T a, T b) {
  if(a == 0) return b;
  return GCD(b%a, a);
}

template <class T>
T modpow(T x, T p){
    T res = 1;
    while(p > 0){
        if(p&1) res *= x;
        x *= x;
        p /= 2;
    }
    return res;
}

template <class T>
void print(T a[], ll n){
    for (ll i = 0; i < n; i++) std::cout << a[i] << ' ';
    cout << endl;
}

template<class T>
void printc(T c){
    for(auto const& v: c) std::cout << v << ' ';
    cout << endl;
}

struct HASH{
  size_t operator()(const pair<long,long>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};

bool pair_sort(const pair<int, int> &p1, const pair<int,int> &p2){
    if(p1.first != p2.first) return p1.first < p2.first;
    else return p1.second < p2.second;
}

const int INF = std::numeric_limits<int>::max();
const ll M_INF = std::numeric_limits<ll>::min();

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}

void solution(){
    string s;
    cin >> s;
    int a = 0, b = 0;
    from(i, 3){
        if(s[i] == 'A') a++;
        else b++;
    }

    if(a > 0 && b > 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}   