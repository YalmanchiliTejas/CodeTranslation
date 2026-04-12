#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    ll n;
    cin >> n;
    n *= 100;
    ll x;
    cin >> x;
    n += x * 10;
    cin >> x;
    n += x;
    if(n % 4)
        cout << "NO";
    else
        cout << "YES";
}
