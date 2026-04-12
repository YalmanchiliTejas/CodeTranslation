#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> deq;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (i % 2 == 0) deq.push_back(a);
        else deq.push_front(a);
    }

    if (n % 2 == 0) {
        cout << deq[0]; deq.pop_front();
        while (!deq.empty()) {
            cout << " " << deq[0]; deq.pop_front();
        }
    } else {
        cout << deq[deq.size() - 1]; deq.pop_back();
        while (!deq.empty()) {
            cout << " " << deq[deq.size() - 1]; deq.pop_back();
        }
    }
    cout << endl;

    return 0;
}