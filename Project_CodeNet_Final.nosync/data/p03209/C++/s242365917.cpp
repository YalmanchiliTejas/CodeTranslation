#include<iostream>
using namespace std;
#define ll long long

ll all(ll n)
{
    if(n < 0) return 0;
    if(n == 0) return 1;
    else return all(n-1) * 2 + 3;
}

ll apy(ll n)
{
    if(n == 0) return 1;
    return apy(n-1) * 2 + 1;
}

ll pty(ll n, ll k)
{
    ll a = all(n-1);
    ll sum = (k > a+1);
    if(k <= 0 || k <= n) return 0;
    if(n == 0) return 1;
    if(k >= all(n)) return apy(n-1) * 2 + 1;
    if(k <= a) return pty(n-1, k-1);
    sum += apy(n-1);
    if(k > a + 2) sum += pty(n-1, k - (a+2));
    return sum;
}

int main()
{
    ll n, x;
    cin >> n >> x;
    cout << pty(n, x) << endl;
    return 0;
}