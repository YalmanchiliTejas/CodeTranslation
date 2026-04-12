#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char a, b, c;
    cin >> a >> b >> c;

    cout << (a == b && b == c ? "No" : "Yes") << endl;

    return 0;
}
