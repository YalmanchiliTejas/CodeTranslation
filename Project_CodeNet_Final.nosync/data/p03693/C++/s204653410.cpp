#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, g, b, n = 3, total = 0, m = 100, i = 0;
    cin >> r >> g >> b;
    vector <int> a = {r,g,b};
    while(n--){
        total += m * a[i++];
        m/=10;
    }
    total%4 == 0? cout << "YES" << endl : cout << "NO" << endl;
    return 0;

}
