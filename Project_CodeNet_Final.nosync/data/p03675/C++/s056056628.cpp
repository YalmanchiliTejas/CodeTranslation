#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <deque>

using namespace std;

deque<int> q;

int main(int argc, char const *argv[]) {
    
    int n; cin >> n;

    for (int i = 1; i <= n; i ++) {
        int x; scanf("%d", &x);
        if (i & 1) q.push_front(x);
        else q.push_back(x);
    }

    if (n & 1) {
        while (q.size() > 1) {
            printf("%d ", q.front());
            q.pop_front();
        }
        printf("%d\n", q.front());
    }
    else {
        while (q.size() > 1) {
            printf("%d ", q.back());
            q.pop_back();
        }
        printf("%d\n", q.back());
    }

    return 0;
}