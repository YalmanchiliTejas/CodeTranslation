#include <bits/stdc++.h>
using namespace std;

int main() {
    int e[12];
    for(int a = 0; a < 12; ++a) {
        cin >> e[a];
    }
    sort(e,e+12);

    if(e[0] == e[3] && e[4] == e[7] && e[8] == e[11]) {
        cout << "yes" << endl;
    }else {
        cout << "no" << endl;
    }
}