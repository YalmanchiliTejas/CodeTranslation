#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

int main() {
    deque<int> dq;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (i % 2 == 0)
            dq.push_back(x);
        else
            dq.push_front(x);
    }
    vector<int> vv;
    for (int i: dq)
        vv.push_back(i);
    if (n % 2 == 1)
        reverse(vv.begin(), vv.end());
    for (int i = 0; i < vv.size(); ++i)
        printf("%d ", vv[i]);
    printf("\n");
    return 0;
}


