#include <bits/stdc++.h>
#define base 1000000007LL
#define ll long long
#define ld double
#define X first
#define Y second
#define pb push_back
#define EPS 1e-22
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORE(i,a,b) for (int i = (a); i >= (b); i--)
#define FORALL(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
using namespace std;
typedef pair<int, int> II;
typedef pair<II, int> III;

int n;
int f[30], g[30];

int main()
{
    ios::sync_with_stdio(0);
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n;
    FOR(i,0,25) g[i] = 1000000000;
    FOR(i,1,n) {
        string s;
        cin >> s;
        ms(f, 0);
        FOR(j,0,s.length()-1) f[s[j]-'a']++;
        FOR(j,0,25) g[j] = min(g[j], f[j]);
    }
    //FOR(i,0,25) cout << g[i] << " ";
    FOR(i,0,25)
        while (g[i]) {
            g[i]--;
            cout << char(i+'a');
        }
    return 0;
}
