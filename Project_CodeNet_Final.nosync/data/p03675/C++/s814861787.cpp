#include <ios>
#include <iomanip>
#include <iostream>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <climits>
 
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
//#define MOD 1000000007
#define MOD 1000000007
#define INF (1e9)

#define PI (acos(-1))
#define print(x) cout << x << endl
 
ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
typedef pair <ll,ll> P;

ll nCrModp(ll n, ll r, ll p)
{
    ll C[r+1];
    memset(C, 0, sizeof(C));

    C[0] = 1;

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
}

int main()
{
    ll n;
    cin >> n;
    list<ll> b;
    if (n % 2 == 0) {
        rep(i, n) {
            ll a;
            cin >> a;
            if (i % 2 != 0) b.push_front(a);
            else b.push_back(a);
        }
    } else {
        rep(i, n) {
            ll a;
            cin >> a;
            if (i % 2 == 0) b.push_front(a);
            else b.push_back(a);
        }
    }
    for(ll i : b) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}