#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll m = 1e18;

    ll n = min(X, Y);
    m = min(m, A * (X - n) + B * (Y - n) + 2 * n * C); 
    m = min(m, A * X + B * Y); 
    ll N = max(X, Y);
    m = min(m, 2 * N * C); 
    put(m);

    return 0;
}