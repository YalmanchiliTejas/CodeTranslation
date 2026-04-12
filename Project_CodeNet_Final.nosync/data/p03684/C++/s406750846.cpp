#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define SZ(a) ((int)a.size())
typedef long long ll;

int N, E, p[100100], ans;
pair<int, int> a[100100], b[100100];
tuple<int, int, int> e[200200];

int g (int i) { return p[i] == i ? i : p[i] = g(p[i]); }

int main () {
        scanf("%d", &N);
        fo(i, 0, N) {
                int x, y; scanf("%d %d", &x, &y);
                a[i] = MP(x, i);
                b[i] = MP(y, i);
                p[i] = i;
        }

        sort(a, a+N), sort(b, b+N);
        fo(i, 1, N) {
                int x,y,c;

                x = a[i-1].second, y = a[i].second, c = a[i].first-a[i-1].first;
                e[E++] = make_tuple(c,x,y);

                x = b[i-1].second, y = b[i].second, c = b[i].first-b[i-1].first;
                e[E++] = make_tuple(c,x,y);
        }

        sort(e, e+E);
        fo(i, 0, E) {
                int c,x,y; tie(c,x,y) = e[i];
                x = g(x), y = g(y);
                if (x != y) {
                        ans += c;
                        p[x] = y;
                }
        }

        printf("%d\n", ans);
        return 0;
}

