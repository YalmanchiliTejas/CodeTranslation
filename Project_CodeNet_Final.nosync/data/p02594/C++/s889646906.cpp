#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    
    int X;
    cin >> X;
    
    if ( X >= 30 ){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
