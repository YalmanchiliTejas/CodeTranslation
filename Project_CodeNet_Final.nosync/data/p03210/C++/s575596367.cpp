#include <iostream>
#include <string>
using namespace std;

int main() {
    int x;
    string ans;

    cin >> x;
    if (x == 3) {
        ans = "YES";
    } else if (x == 5) {
        ans = "YES";
    } else if (x == 7) {
        ans = "YES";
    } else {
        ans = "NO";
    }
    cout << ans << endl;
}