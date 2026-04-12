#include <iostream>
#define ll long long

using namespace std;
int n;
const int NMAX = 200005;
const ll MOD = 1e9 + 7;
ll v[NMAX];
ll sp[NMAX];
ll s = 0;

int main()
{
   cin >> n; sp[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> v[i]; sp[i] = v[i];
        sp[i] += sp[i - 1];
        sp[i] %= MOD;
    }
    for(int i = 1; i <= n; i++) {
        int x = sp[i] - v[i];
        while(x <= 0)
            x += MOD;
        s += x * v[i];
        s %= MOD;
    }
    s %= MOD;
    cout << s;
    return 0;
}
