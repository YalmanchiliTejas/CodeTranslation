#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define lpsbd(i, s, b, d) for(size_t i = (s); i < (b); i+=(d))
#define lpsb(i, s, b) for(size_t i = (s); i < (b); i++)
#define lpn(i, n) for(size_t i = 0; i < (n); i++)
#define fa(i, x) for(auto &i: x)
#define vcd(t, n, d) vector<t>(n, d)
#define vc(t, n) vector<t>(n)
#define all(x) (x).begin(), (x).end()

using namespace std;

using ll = long long;

ll s[51], p[51];

ll pinn(int n, ll x)
{
    if (!x) return 0;
    if (!n) return x;
    if (x >= s[n] - 1) return p[n];
    x--;
    if (x <= s[n-1]) return pinn(n-1, x);
    x-=s[n-1];
    if (x == 1) return 1 + p[n-1];
    x--;
    if (x <= s[n-1]) return pinn(n-1, x) + 1 + p[n-1];
    return p[n];
}

int main(void)
{
    int N;
    ll X;
    cin >> N >> X;
    s[0] = p[0] = 1;
    lpn(i, 50)
    {
        s[i+1] = s[i] * 2 + 3;
        p[i+1] = p[i] * 2 + 1;
    }
    cout << pinn(N, X) << endl;
    return 0;
}