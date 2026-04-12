/*
    Author : Wasi Ur Rahman
*/
#include <bits/stdc++.h>
using namespace std;
// defines
#define ll long long int
#define ull unsigned long long int
#define MOD 100000
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define sc scanf
#define pf printf
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(d, min(a, min(b, c)))
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(d, max(a, max(b, c)))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a) * (b) / gcd(a, b))
#define PI 3.141592653589793238462643
#define no cout << "NO" << endl;
#define yes cout << "YES" << endl;
#define elif else if
/* important funct */
ll Int()
{
    ll c;
    cin >> c;
    return c;
}
#define Int Int()
void sortString(string &str)
{
    sort(str.begin(), str.end());
}
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    for (ll i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}
ll ManualGcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll ManualLcm(ll a,ll b)
{
    return((a)*(b)/gcd(a,b));
}
ll fact(ll n)
{
    ll res = 1;
    for(ll i = n;i>=1;i--)
        res *= i;
    return res;
}
ll nCr(ll n,ll r)
{
    return (fact(n)/(fact(r)*fact(n-r)));
}
ll nPr(ll n,ll r)
{
    return fact(n)/fact(n-r);
}
// Main
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll a=Int;
    ll b=Int;
    if(a <= b)
        cout << "Yes" << endl;
    else cout << "No" <<endl;
}
