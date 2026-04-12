#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    list<int> b;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;

        if (i % 2 == 0) {
            b.push_front(a);
        } else {
            b.push_back(a);
        }
    }

    if (n % 2 == 0) {
        reverse(b.begin(), b.end());
    }

    for (int i : b) {
        cout << i << ' ';
    }
    cout << endl;
}
