#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; ++i)
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define F first
#define S second
#define OUT(x) cout << (x) << "\n"
using namespace std;
using point = pair< int,int >;
using ll = long long;

int main() {
    int n;
    scanf("%d", &n);
    int ary[n];

    REP(i, n) {
        scanf("%d", &ary[i]);
    }

    bool state = false;
    deque< int > q;

    REP(i, n) {
        if (state) {
            q.push_front(ary[i]);
            state = !state;
        } else {
            q.push_back(ary[i]);
            state = !state;
        }
    }

    if (state) {
        for (int i = n - 1; i >= 0; --i) {
            if (i != n - 1) printf(" ");
            printf("%d", q[i]);
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (i) printf(" ");
            printf("%d", q[i]);
        }
    }

    OUT("");

    return 0;
}

