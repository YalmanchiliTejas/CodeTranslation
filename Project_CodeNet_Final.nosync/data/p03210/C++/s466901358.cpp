#include<iostream>
using namespace std;

int main() {
    int x; cin >> x;
    string ans = "NO";
    if (x == 3 || x == 5 || x == 7) ans = "YES";
    cout << ans << endl;
    return 0;
}