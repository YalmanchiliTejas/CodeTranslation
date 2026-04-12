#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <cctype>
#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const ll INFLL = 1001001001001001001;  // > 10^18
const int MOD = (int)1e9 + 7;
const ll MODLL = (ll)1e9 + 7;
const double EPS = 1e-9;



int main() {
    
    int n; cin >>n;
    vector<int> a(n); REP(i,n) cin >> a[i];
    vector<int> v;
    v.push_back(a[0]);

    for (int i = 1; i < n; i++) {
        int this_a = a[i];
        int ok = v.size();
        int ng = -1;
        while (abs(ok - ng) > 1) {
            int m = (ok+ng)/2;
            if (v[m] < this_a) {
                ok = m;
            } else {
                ng = m;
            } 
        }
        if (ok != v.size()) {
            v[ok] = this_a;
        } else {
            v.push_back(this_a);
        }
    }
    
    cout << v.size() << endl;
    return 0;

}


