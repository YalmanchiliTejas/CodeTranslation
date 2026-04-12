#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define print(x) cout << x << endl

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll MOD = 1000000007;


int main()
{
    ll n, m;
    cin >> n >> m;
    if (n == m)
        print("Yes");
    else
        print("No");
    return 0;
}
