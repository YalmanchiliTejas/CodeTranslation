#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
//#define int long long
template<typename T> inline bool chmax(T& a,T b) { if (a < b) { a = b; return true; } return false; }
template<typename T> inline bool chmin(T& a,T b) { if (a > b) { a = b; return true; } return false; }

int main() {
    int N;
    cin >> N;
    cout << N*800 - (N/15) * 200 << endl;
    return 0;
}