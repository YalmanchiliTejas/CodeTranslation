#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-10
#define int long long
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

string path;
vb used(8, false);
vvb graph(8, vb(8, false));
int n, m, ret = 0;

void mp();
int search();

signed main()
{
    cin >> n >> m;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        graph[a-1][b-1] = true;
        graph[b-1][a-1] = true;
    }
    used[0] = true;
    path.pb(0);
    mp();
    cout << ret << endl;

    return 0;
}

void mp()
{
    if (path.size() == n) {
        ret += search();
    } else {
        Rep(i, n) {
            if (!used[i]) {
                used[i] = true;
                path.pb(i);
                mp();
                used[i] = false;
                path.pop_back();
            }
        }
    }
}

int search()
{
    int state = path[0];
    Rep(i, n) {
        if (!graph[state][path[i]]) {
            return 0;
        } else {
            state = path[i];
        }
    }
    return 1;
}

