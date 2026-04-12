#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;

const int N = 2e5;

deque<int> q;

int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (i & 1) q.push_back(x);
            else q.push_front(x);
    }
    if ((n & 1) == 0) {
        for (deque<int>::iterator it = q.begin(); it != q.end(); ++it) {
            printf("%d ", *it);
        }
        return 0;
    } else {
        deque<int>::iterator it = q.end();
        --it;
        for (; it != q.begin(); --it) {
            printf("%d ", *it);
        } printf("%d\n", q.front());
        return 0;
    }
    return 0;
}