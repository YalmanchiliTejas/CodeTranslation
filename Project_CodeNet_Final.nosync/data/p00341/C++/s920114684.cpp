#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

int main() {
    int e[12];
    REP(i,12){
        cin >> e[i];
    }
    sort(e,e+12);
    bool ok = true;
    REP(i,3){
        REP(j,3){
            ok &= e[i*4+j] == e[i*4+j+1];
        }
    }
    cout << (ok?"yes":"no") << endl;
    return 0;
}

