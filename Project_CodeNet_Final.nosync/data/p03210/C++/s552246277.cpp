#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll gcd(ll a, ll b){return b ? gcd(b, a % b) : a;}

int main(){

    ll X;
    
    cin >> X;

    cout << (X == 7 || X == 5 || X == 3 ? "YES" : "NO") << endl;

    return 0;
}