#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define INF 1145141919
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int ny, nx;
typedef long long int ll;
using namespace std;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll lcm(ll m, ll n)
{
    if ((0 == m) || (0 == n))
        return 0;
    return ((m / gcd(m, n)) * n);
}

ll llpow(ll x, ll y)
{
    ll ans = 1;
    REP(i, y)
    ans *= x;
    return ans;
}

int ctoi(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return 0;
}
////////////////////////////////////////////////////////////////////
int main()
{
    int N,K;
    string S;

    cin >> N >> S >> K;

    char res = S[K-1];

    REP(i,S.size()){
        if(S[i]!=res){
            S[i]='*';
        }
    }

    cout << S << endl;

    return 0;
}
