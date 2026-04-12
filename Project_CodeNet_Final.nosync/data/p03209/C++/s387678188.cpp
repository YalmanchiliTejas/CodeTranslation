#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long int ll;
vector<ll> len, patty;

ll recLength(ll n)
{
    return n == 0 ? 1 : recLength(n - 1) * 2 + 3;
}

ll recPatty(ll n)
{
    return n == 0 ? 1 : recPatty(n - 1) * 2 + 1;
}

ll calcPatty(ll x, ll n)
{
    if (x <= 0 && n == 0)
    {
        return 0;
    }
    else if (x > 0 && n == 0)
    {
        return 1;
    }
    else if (x <= len[n - 1] + 1)
    {
        return calcPatty(x - 1, n - 1);
    }
    else
    {
        return patty[n - 1] + 1 + calcPatty(x - len[n - 1] - 2, n - 1);
    }
}

int main()
{
    ll N, K;
    cin >> N >> K;

    for (ll i = 0; i < N; i++)
    {
        len.push_back(recLength(i));
        patty.push_back(recPatty(i));
    }
    cout << calcPatty(K, N) << endl;
}
