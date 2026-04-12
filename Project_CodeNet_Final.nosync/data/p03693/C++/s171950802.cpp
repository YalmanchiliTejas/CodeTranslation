#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 2e5;
const int INF = 1e9 + 7;
/*
void init(int x, int l, int r) {
    if (l == r) {
        tree[x] = INF;
    } else {
        int mid = (l + r) / 2;
        init(x + x, l, mid);
        init(x+x+1, mid + 1, r);
        tree[x] = min(tree[x + x], tree[x + x + 1]);
    }
}
int get(int x, int l, int r, int tl, int tr) {
    if (r < tl || tr < l) {
        return INF;
    }
    if (tl <= l && r <= tr) {
        return tree[x];
    }
    int mid = (l + r) / 2;
    return min(get(x + x, l, mid, tl, tr), get(x+x+1, mid + 1, r, tl, tr));
}
void upd(int x, int l, int r, int pos, int val) {
    if (l == r) {
        tree[x] = min(tree[x], val);
    } else {
        int mid = (l + r) / 2;
        if (pos <= mid) {
            upd(x + x, l, mid, pos, val);
        } else {
            upd(x+x+1, mid + 1, r, pos, val);
        }
        tree[x ] =min(tree[x + x], tree[x + x +1]);
    }
}

*/
int main() {
    int r, g, b;
    cin >> r >> g >> b;
    r *= 10;
    r += g;
    r *= 10;
    r += b;
    if (r % 4 == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}
