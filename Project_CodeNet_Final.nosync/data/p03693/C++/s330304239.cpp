#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll gcd(ll a, ll b){return b ? gcd(b, a % b) : a;}

int main(){

    ll r, g, b;

    cin >> r >> g >> b;

    cout << ((g * 10 + b) % 4 ? "NO" : "YES") << endl;

    return 0;
}