#include <bits/stdc++.h>

using namespace std;


int main() {

    int x;
    string res1, res2;
    res1 = "YES";
    res2 = "NO";
    cin >> x;

    if(x == 7 || x == 5 || x == 3) {
        cout << res1 << endl;
    } else {
        cout << res2 << endl;
    }

    return 0;
}
