#include <bits/stdc++.h>
#define for0(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define V vector<int>
#define VP vector<pair<int, int> >
#define clr(A, x) memset(A, x, sizeof(A))
#define cpy(A, B) memcpy(A, B, sizeof(B))
#define g(s) getline(cin, s) ///ai grija la fin/cin ///
#define FASTIO ios_base::sync_with_stdio(0)
const long long INFLL = 2 * 1e18 + 100;
const int INFINT = 2 * 1e9 + 100;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
//ifstream fin("input.txt");
//ofstream fout("output.txt");
void die()
{
    cout << "-1";
    exit(0);
}
const int NMAX = 1e5 + 5;
const int MOD = 1e9 + 7; /// careful here (7 or 9, 66.. etc)
const double PI = atan(1) * 4;
const double EPS = 1e-12;



int main()
{
    FASTIO;
    int a, b, c;
    cin >> a >> b >> c;
    if((b * 10 + c) % 4 == 0) cout << "YES"; else cout << "NO";

    return 0;
}
