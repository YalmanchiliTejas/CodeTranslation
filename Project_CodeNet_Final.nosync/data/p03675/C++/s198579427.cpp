#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
    int n;
    cin >> n;
    bool front;
    front = n % 2 == 0 ? false : true;

    deque<int> q;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (front) {
            q.push_front(a);
        } else {
            q.push_back(a);
        }
        front = !front;
    }

    for (auto itr = q.begin(); itr != q.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;

    return 0;
}
