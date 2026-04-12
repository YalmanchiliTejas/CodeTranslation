#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

string s;
ll k;
ll ans;

ll f(ll p, ll q)
{
    if(q == 0) return 1;
    if(p >= s.size()) return 0;
    if(s[p] == '0') return f(p + 1, q);
    ll re = 0;
    re += f(p + 1, q - 1);
    ll x = 1;
    for(ll i = 0; i < q; i++) x *= 9;
    ll lt = s.size() - p - 1;
    if(q == 1) re += lt * x + (s[p] - '1') * x / 9;
    else if(q == 2) re += lt * (lt - 1) / 2 * x + (s[p] - '1') * lt * x / 9;
    else re += lt * (lt - 1) * (lt - 2) / 6 * x + (s[p] - '1') * lt * (lt - 1) / 2 * x / 9;
    return re;
}

int main()
{
    cin>>s>>k;
    cout<<f(0, k);
    return 0;
}
