#include<bits/stdc++.h>


using namespace std;
#define ll  long long
#define ld  long double
#define endl '\n'
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll mod = 1e9 + 7;
const double PI = 3.141592653589793238463;
const int MAXN = 2e3 + 5;
bool isPrime[MAXN];
void sevie() {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;
    for (ll i = 2; i * i <= MAXN; i++) {
        if (isPrime[i]) {
            for (ll j = i * 2; j <= MAXN; j += i) {
                isPrime[j] = 0;

            }
        }
    }
}
ll fastPow(ll x, ll b) {
    if (b == 0)
        return 1;
    else if (!(b & 1)) {
        return fastPow(x * x, b / 2);
    } else
        return x * fastPow(x * x, (b - 1) / 2);
}
//__builtin_popcount ();
bool isPrim(int n) {
    if (n == 1 || n == 0)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}



int main() {
    FAST
int a,b;
    cin>>a>>b;
    if(b>=a)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}
