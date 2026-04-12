#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    list<int> l;
    cin >> n;

    while (n--) {
        int tmp;
        cin >> tmp;
        n & 1 ? l.push_back(tmp) : l.push_front(tmp);
    }

    for (int x : l)
        cout << x << " ";
    cout << "\n";

    return 0;
}