#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;
    
    string s;
    if (x == 3 || x == 5 || x == 7) {
        s = "YES";
    } else {
        s = "NO";
    }

    cout << s << endl;

    return 0;
}
