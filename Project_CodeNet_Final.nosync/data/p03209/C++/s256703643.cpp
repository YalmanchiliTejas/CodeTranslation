#include <bits/stdc++.h>
using namespace std;
using Int = long long;
#define REP(i, n) for(int i = 0; i < n; i++)
#define DUMP(range) do{for(auto& x:range){cout<<x<<' ';}cout<<endl;}while(0)

int N;
Int tot[51], pat[51];

Int eat(int n, Int x)
{
    Int ans = 0;
    if (x >= tot[n]) return pat[n];
    // B
    if (x == 0) return ans;
    x--;
    // L(n-1)
    if (x < tot[n-1]) return ans + eat(n-1, x);
    x -= tot[n-1];
    ans += pat[n-1];
    // P
    if (x == 0) return ans;
    x -= 1;
    ans += 1;
    // L(n-1)
    return ans + eat(n-1, x);
}

int main()
{
    Int X; cin >> N >> X;
    tot[0] = pat[0] = 1;
    for (int i = 1; i <= 50; i++) {
        tot[i] = 3 + 2 * tot[i-1];
        pat[i] = 1 + 2 * pat[i-1];
    }
    cout << eat(N, X) << endl;
    return 0;
}