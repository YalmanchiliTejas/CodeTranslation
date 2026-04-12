#include <bits/stdc++.h>

using namespace std;

const int M = 1e5 + 10;
int n, arr[M], seg[M * 4];

int build(int i, int l, int r) {
    if (l == r)
        seg[i] = arr[l];
    else {
        int mid = (l + r) / 2;
        seg[i] = max(build(i * 2 + 1, l, mid), build(i * 2 + 2, mid + 1, r));
    }
    return seg[i];
}

int modify(int i, int l, int r, int j) {
    if ((l < j && r < j) || (l > j && r > j))
        return seg[i];

    if (l == r)
        seg[i] = arr[l];
    else {
        int mid = (l + r) / 2;

        seg[i] = max(modify(i * 2 + 1, l, mid, j), modify(i * 2 + 2, mid + 1, r, j));
    }
    return seg[i];
}

int mxQ(int i, int L, int R, int l, int r) {
    if (l > R || r < L)
        return 0;

    if (L >= l && R <= r)
        return seg[i];

    int mid = (L + R) / 2;

    return max(mxQ(i * 2 + 1, L, mid, l, r), mxQ(i * 2 + 2, mid + 1, R, l, r));
}

int getN(int x, int l, int r) {
    if (l == n)
        return -1;

    if (l == r)
        return arr[l] > x ? l : -1;

    int mid = (l + r) / 2;

    if (mxQ(0, 0, n - 1, l, mid) > x)
        return getN(x, l, mid);

    if (mxQ(0, 0, n - 1, mid + 1, r) > x)
        return getN(x, mid + 1, r);

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int c = 1, ans[n] = {};

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(0, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (!ans[i]) {
            int cur = arr[i];

            ans[i] = c;
            arr[i] = -1;
            modify(0, 0, n - 1, i);

            int next = getN(cur, i + 1, n - 1);

            while (next != -1) {
                cur = arr[next];

                ans[next] = c;
                arr[next] = -1;

                modify(0, 0, n - 1, next);

                next = getN(cur, next + 1, n - 1);
            }

            c++;
        }
    }

    cout << *max_element(ans, ans + n) << '\n';

    return 0;
}