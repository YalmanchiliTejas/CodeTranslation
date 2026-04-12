#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
        int n, q;
        scanf("%d%d", &n, &q);
        vector<int> g(n);
        for (int i = 0; i < n; i ++) g[i] = i;
        set<int> pos;
        pos.insert(0);
        pos.insert(1);
        int ball = 0;
        while (q --) {
                int a, b;
                scanf("%d%d", &a, &b);
                a --, b --;
                swap(g[a], g[b]);
                if (a == ball) ball = b;
                else if (b == ball) ball = a;
                //for (int i = 0; i < n; i++) cerr << g[i] << ' ';
                //cerr << endl;
                if (ball > 0) pos.insert(g[ball - 1]);
                if (ball < n - 1) pos.insert(g[ball + 1]);
        }
        printf("%d\n", (int) pos.size());
        return 0;
}

