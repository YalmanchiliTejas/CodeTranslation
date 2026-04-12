#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    deque<int> A;
    while (n--) {
        int x;
        cin >> x;
        if (n & 1) A.push_back(x);
        else A.push_front(x);
    }
    while (!A.empty()) {
        printf("%d ", A.front());
        A.pop_front();
    }
    return 0;
}