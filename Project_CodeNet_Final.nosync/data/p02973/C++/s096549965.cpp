#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, a;
    cin >> N;
    deque<int> deq;
    for (int i = 0; i < N; i++) {
        cin >> a;
        int idx = lower_bound(deq.begin(), deq.end(), a) - deq.begin();
        if (idx) {
            deq[idx-1] = a;
        } else {
            deq.push_front(a);
        }
    }
    cout << deq.size() << endl;
}