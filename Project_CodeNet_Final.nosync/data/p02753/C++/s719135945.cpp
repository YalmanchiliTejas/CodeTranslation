#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define REPS(i,n) for(int i=1;i<=(int)(n);i++)
using namespace std;
using ll = long long;
using ld = long double;

int main(void) {
    string S;
    cin >> S;

    bool flg = true;
    REP (i, 3) {
        char tmp;
        if (i == 0) {
            tmp = S.at(0);
        }
        if (tmp != S.at(i)) {
            flg = false;
        }
    }
    if (flg) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}