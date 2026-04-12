#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#define REP(i, n) for(int i = 0; i < n; i++)
//#define REPR(i, n) for(int i = n; i >= 0; i--)
//#define FOR(i, m, n) for(int i = m; i < n; i++)
//#define INF 1e9
// template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
// template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;

int main() { //int argc, const char * argv[]

    cin.tie(0);
    ios::sync_with_stdio(false);

    string s, ans;
    cin >> s;

    if (s == "AAA" || s == "BBB"){
        ans = "No";
    } else {
        ans = "Yes";
    }

    cout << ans;
   
}
