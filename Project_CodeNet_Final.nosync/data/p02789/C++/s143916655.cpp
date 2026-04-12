#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define pb push_back
const int maxn = 10000;
const int INF32 = 1'050'000'000;
const long long INF64 = 4'000'000'000'000'000'000;
const int MOD7 = 1'000'000'007;
const int MOD9 = 1'000'000'009;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int n, m;

int main()
{
    cin >> n >> m;
    if(n == m) cout << "Yes" << endl;
    else cout << "No" << endl;     
}