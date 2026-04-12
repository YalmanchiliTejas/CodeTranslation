#include "bits/stdc++.h"
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define mFOR(i, a, b) for (int i = a; i > b; i--)
#define MP make_pair
#define PB push_back
#define N 107
#define INF 1000000000
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main()
{
    int n, h[N] = {};
    cin >> n;
    FOR(i, 1, n + 1)
    {
        cin >> h[i];
    }

    int ctr = 1;
    bool flag;
    FOR(i, 1, n + 1)
    {
        FOR(j, 1, i)
        {
            if(h[j]>h[i])
                break;
            if(j==i-1)
                ctr++;
        }
    }
    cout << ctr << endl;
    return 0;
}