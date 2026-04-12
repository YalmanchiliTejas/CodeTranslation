#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<char> bus(3);
    for (int i = 0; i < 3; i++) {
        cin >> bus.at(i);
    }
    if (bus.at(0) != bus.at(1) || bus.at(1) != bus.at(2))
        cout << "Yes" << endl;
    else cout << "No" << endl;

}