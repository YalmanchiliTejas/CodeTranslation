#include <iostream>
#include <deque>

using namespace std;

int n;
deque<int> q;

int main() {
    cin >> n;
    bool flag = false;

    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        if(flag) {
            q.push_front(v);
        } else {
            q.push_back(v);
        }
        flag ^= 1;
    }

    if(n % 2 == 0) {
        for(int i = 0; i < n; i++) cout << q[i] << ' ';
    } else {
        for(int i = n - 1; i >= 0; i--) cout << q[i] << ' ';
    }
    cout << endl;

    return 0;
}
