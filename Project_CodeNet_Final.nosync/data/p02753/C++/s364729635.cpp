#include <iostream>
#include <vector>
using namespace std;

#define int long long

signed main() {
    string s;
    cin >> s;

    if(s == "AAA" || s == "BBB") {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;
}