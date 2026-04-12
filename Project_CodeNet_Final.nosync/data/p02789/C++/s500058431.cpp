#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    if (n == m)
        cout << "Yes";
    else
        cout << "No";
    cout << endl;
    return 0;
}
