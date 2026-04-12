#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    if (n == m) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}