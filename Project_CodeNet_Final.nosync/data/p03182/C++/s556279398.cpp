#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int a[N];
int f[N];
long long t[4 * N];
long long lz[4 * N];
vector < int > b[N], e[N];

void push(int x)
{
        if(lz[x]){
                t[x * 2] += lz[x];
                lz[x * 2] += lz[x];
                t[x * 2 + 1] += lz[x];
                lz[x * 2 + 1] += lz[x];
                lz[x] = 0;
        }
}

void upd(int x, int l, int r, int tl, int tr, long long y)
{
        if(tl > tr){
                return;
        }
        if(l == tl && r == tr){
                t[x] += y;
                lz[x] += y;
                return;
        }
        push(x);
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr), y);
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y);
        t[x] = max(t[x * 2], t[x * 2 + 1]);
}

long long get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return -1e18;
        }
        if(l == tl && r == tr){
                return t[x];
        }
        push(x);
        int m = (l + r) / 2;
        return max(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int l, r;
                cin >> l >> r >> a[i];
                f[i] = l;
                b[l].push_back(i);
                e[r].push_back(i);
        }
        long long d = 0, best = 0;
        for(int i = 1; i <= n; i++){
                upd(1, 0, n, i - 1, i - 1, d);
                for(int x: b[i]){
                        upd(1, 0, n, 0, i - 1, a[x]);
                }
                d = get(1, 0, n, 0, i - 1);
                for(int x: e[i]){
                        upd(1, 0, n, 0, f[x] - 1, - a[x]);
                }
                best = max(best, d);
        }
        cout << best << "\n";
}

