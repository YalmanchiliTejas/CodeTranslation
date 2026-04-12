#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
vector<ll> p;
vector<ll> h;

ll f(int level, ll x)
{
    if(level==0) return 1;
    if(x==1) return 0;
    if(x>=2 && x <= h[level-1]+1) return f(level-1, x-1);
    if(x==h[level-1]+2) return p[level-1]+1;
    if(x>=h[level-1]+3 && x <= 2*h[level-1]+2) return f(level-1, x-h[level-1]-2)+p[level-1]+1;
    if(x>=2*h[level-1]+3) return 2*p[level-1]+1;
}

int main()
{
    int n;ll x;
    cin >> n >> x;
    p.resize(n+1);
    h.resize(n+1);
    h[0] = 1;
    p[0] = 1;
    for (int i = 1; i < n+1; i++)
    {
        p[i] = p[i-1]*2+1;
        h[i] = h[i-1]*2+3;
    }
    cout << f(n,x) << endl;
}