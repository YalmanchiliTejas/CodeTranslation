#include <bits/stdc++.h>
#define base 1000000007LL
#define ll long long
#define X first
#define Y second
#define pb push_back
#define MAXN 21010
#define Scan(a) scanf("%I64d", &a)
#define CLR(a) memset(a,0,sizeof(a))
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORE(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)

using namespace std;

typedef pair<int, int> II;
typedef vector<II> vi;

int n, m;
bool a[10][10];
int permu[10];

int main()
{
    ios::sync_with_stdio(0);
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> m;
    FOR(i,1,m) {
        int u, v;
        cin >> u >> v;
        a[u][v] = a[v][u] = true;
    }
    FOR(i,1,n) permu[i] = i;
    int res = 0;
    do {
        if (permu[1] != 1) break;
        bool co = true;
        FOR(i,2,n)
            if (!a[permu[i]][permu[i-1]]) {
                co = false;
                break;
            }
        if (co) res++;
    } while (next_permutation(permu+1, permu+n+1));
    cout << res;
    return 0;
}
