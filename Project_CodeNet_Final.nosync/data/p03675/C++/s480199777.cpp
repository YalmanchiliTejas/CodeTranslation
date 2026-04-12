#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> d;
    bool isReversed = false;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        if (isReversed) {
            d.push_front(value);
        } else {
            d.push_back(value);
        }

        isReversed = !isReversed;
    }

    if (isReversed) {
        reverse(d.begin(), d.end());
    }

    for (auto& i : d) {
        cout << i << " ";
    }

    cout << endl;
}