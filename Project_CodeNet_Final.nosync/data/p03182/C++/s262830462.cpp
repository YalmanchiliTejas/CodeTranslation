#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

const int maxN = 2e5 + 10;
const int inf = 1e18;

typedef pair<int, int> ii;

int n, m, sum, st[maxN * 4], lazy[maxN * 4];

vector <ii> a[maxN];

void push(int id){
    st[id * 2] += lazy[id];
    lazy[id * 2] += lazy[id];
    st[id * 2 + 1] += lazy[id];
    lazy[id * 2 + 1] += lazy[id];
    lazy[id] = 0;
}

void update(int x, int y, int d, int id = 1, int l = 0, int r = n){
    if(x > r || l > y)
        return;

    if(l >= x && r <= y){
        st[id] += d;
        lazy[id] += d;
        return;
    }

    int mid = (l + r) / 2;
    push(id);
    update(x, y, d, id * 2, l, mid);
    update(x, y, d, id * 2 + 1, mid + 1, r);
    st[id] = max(st[id * 2],st[id * 2 + 1]);
}

int get(int x, int y, int id = 1, int l = 0, int r = n){
    if(x > r || l > y)
        return -inf;

    if(l >= x && r <= y)
        return st[id];

    int mid = (l + r) / 2;
    push(id);
    return max(get(x, y, id * 2, l, mid), get(x, y, id * 2 + 1, mid + 1, r));
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int l,r,x;
        cin >> l >> r >> x;
        a[r].push_back({l,x});
        sum += x;
    }

    update(0, n,sum);
    for(int i = 1; i <= n; ++i){
        update(i, i, get(0, i - 1) - sum);
        for(auto j : a[i])
            update(0, j.fi - 1, -j.se);
    }

    cout << st[1] << endl;
}
