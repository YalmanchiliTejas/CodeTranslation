#include <stdio.h>

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}
#ifdef LOCAL
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S;
    cin >> S;
    ll A_count=0;
    ll B_count=0;
    REP(i, S.length()){
        if(S[i]=='A') A_count++;
        if(S[i]=='B') B_count++;
    }
    if(A_count*B_count==0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }

    return 0;
}
