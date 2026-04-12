#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    deque<int> dq;
    for(int i=0; i<N; i++) {
        int a;
        cin >> a;
        if(i%2) {
            dq.push_front(a);
        } else {
            dq.push_back(a);
        }
    }

    if(N%2) {
        reverse(dq.begin(), dq.end());
    }

    for(auto e: dq) {
        cout << e << ' ';
    }
    return 0;
}
