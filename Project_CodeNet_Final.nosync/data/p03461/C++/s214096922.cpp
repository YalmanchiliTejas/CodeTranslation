#include <bits/stdc++.h>
using namespace std;

int d[11][11];
bool marked[11][11];
int n, m;

int verif(int x, int y, int add)
{
    int ans(0);
    for (int i(1); i <= n; i++) {
        for (int j(1); j <= m; j++) {
            if (x * i + y * j + add == d[i][j] && !marked[i][j])
                ans++;
            else if (x * i + y * j + add < d[i][j])
                ans = -1e9;
        }
    }
    return ans;
}
void mark(int x, int y, int add)
{
    for (int i(1); i <= n; i++) {
        for (int j(1); j <= m; j++) {
            if (x * i + y * j + add == d[i][j])
                marked[i][j] = 1;
        }
    }
}

struct Edge { int x, y, cost; };

vector <Edge> ans;
vector <int> lantx, lanty;
int s, dest;
int cnt;

void mk_lant(vector <int> & lant, int l)
{
    while (lant.size() <= l)
        lant.push_back(++cnt);
}

void mk_choice(int x, int y, int simple)
{
    if (x < y) {
        mk_lant(lanty, y);
        int last(lanty[y]);
        while (x--) {
            ans.push_back((Edge) { last, ++cnt, -1 });
            last = cnt;
        }
        while (simple > 0) {
            ans.push_back((Edge) { last, ++cnt, (simple > 100 ? 100 : simple) });
            last = cnt;
            simple -= 100;
        }
        if (last == lanty[y])
            ans.push_back((Edge) { last, dest, 0 });
        else {
            cnt--;
            ans.back().y = dest;
        }
    }
    else {
        mk_lant(lantx, x);
        int last(lantx[x]);
        while (y--) {
            ans.push_back((Edge) { last, ++cnt, -2 });
            last = cnt;
        }
        while (simple > 0) {
            ans.push_back((Edge) { last, ++cnt, (simple > 100 ? 100 : simple) });
            last = cnt;
            simple -= 100;
        }
        if (last == lantx[x])
            ans.push_back((Edge) { last, dest, 0 });
        else {
            cnt--;
            ans.back().y = dest;
        }
    }
}

int main()
{
    s = 1, dest = 2;
    cnt = 2;
    lantx.push_back(s);
    lanty.push_back(s);
    cin >> n >> m;
    for (int i(1); i <= n; i++) {
        for (int j(1); j <= m; j++)
            cin >> d[i][j];
    }

    bool pus(1);
    int best(0), x, y, add;
    while (pus) {
        pus = 0;
        best = 0;
        for (int i(0); i <= 100; i++) {
            for (int j(0); j <= 100; j++) {
                for (int k(0); k <= 100; k++) {
                    int q = verif(i, j, k);
                    if (q > best)
                        best = q, x = i, y = j, add = k;
                }
            }
        }
        if (best) {
            pus = 1;
            mk_choice(x, y, add);
            mark(x, y, add);
        }
    }

    for (int i(1); i <= n; i++) {
        for (int j(1); j <= m; j++) {
            if (!marked[i][j]) {
                cout << "Impossible\n";
                return 0;
            }
        }
    }
    cout << "Possible\n";

    cout << cnt << ' ' << ans.size() + lantx.size() - 1 + lanty.size() - 1 << '\n';
    for (int i(1); i < lantx.size(); i++)
        cout << lantx[i - 1] << ' ' << lantx[i] << " X\n";
    for (int i(1); i < lanty.size(); i++)
        cout << lanty[i - 1] << ' ' << lanty[i] << " Y\n";

    for (auto i : ans) {
        cout << i.x << ' ' << i.y << ' ';
        if (i.cost >= 0)
            cout << i.cost << '\n';
        else
            cout << (i.cost == -1 ? 'X' : 'Y') << '\n';
    }
    cout << s << ' ' << dest << '\n';

    return 0;
}
