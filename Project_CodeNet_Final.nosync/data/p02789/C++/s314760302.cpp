#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
//#define int long long
template<class T> inline bool chmax(T& a,T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a,T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N, M;
    cin >> N >> M;
    if (N == M) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}