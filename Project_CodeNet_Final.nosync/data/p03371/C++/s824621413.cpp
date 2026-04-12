#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> P1;
typedef pair<P, P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i, x) for (long long i = 0; i < x; i++)
#define repn(i, x) for (long long i = 1; i <= x; i++)
#define SORT(x) sort(x.begin(), x.end())
#define ERASE(x) x.erase(unique(x.begin(), x.end()), x.end())
#define POSL(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define POSU(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())
vector<pair<string, P> > vec;
// vector<vector<int>> data(3, vector<int>(4));

void solve(long long A, long long B, long long C, long long X, long long Y) {
    cout << min(min(A * X + B * Y, (X - min(X, Y)) * A + (Y - min(X, Y)) * B +
                                       min(X, Y) * 2 * C),
                max(X, Y) * 2 * C)
         << endl;
}

int main() {
    long long Y;
    long long C;
    long long A;
    long long X;
    long long B;
    scanf("%lld", &A);
    scanf("%lld", &B);
    scanf("%lld", &C);
    scanf("%lld", &X);
    scanf("%lld", &Y);
    solve(A, B, C, X, Y);
    return 0;
}
