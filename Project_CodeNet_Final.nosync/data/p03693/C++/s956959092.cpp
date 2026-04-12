#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << # x << "; "<< x << endl


int main() {
    int r, g, b;
    cin >> r >> g >> b;
    if ((100 * r + 10 * g + b) % 4 == 0) {
        cout << "YES" << endl;
    }
    else if ((100 * r + 10 * g + b) % 4 != 0){
        cout << "NO" << endl;
    }
}