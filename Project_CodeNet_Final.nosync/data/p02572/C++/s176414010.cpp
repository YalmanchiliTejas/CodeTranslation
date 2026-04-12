#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll a[200000], n, e, square;

ll mod(ll a, int b)
{
    if(b == 1) return a;
    if(b == 0) return 1;

    ll tmp = mod(a, b/2);
    if(b%2 == 1) return (((tmp*tmp)%MOD)*a)%MOD;
    else return (tmp*tmp)%MOD;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    if(n == 1)
    {
        cout << a[0]%MOD;
        return 0;
    }

    for(int i = 0; i < n; i++)
        e = (e%MOD+a[i]%MOD)%MOD;

    e = (e%MOD*e%MOD)%MOD;

    for(int i = 0; i < n; i++)
        square = ((square%MOD)+((a[i]%MOD*a[i]%MOD)%MOD)) % MOD;

    cout << ((e%MOD-square%MOD+MOD)%MOD)*mod(2, MOD-2)%MOD;

    return 0;
}
