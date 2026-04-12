#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define lpsbd(i, s, b, d) for(size_t i = (s); i < (b); i+=(d))
#define lpsb(i, s, b) for(size_t i = (s); i < (b); i++)
#define lpn(i, n) for(size_t i = 0; i < (n); i++)
#define fa(i, x) for(auto &i: x)
#define vcd(t, n, d) vector<t>(n, d)
#define vc(t, n) vector<t>(n)
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

int main(void)
{
    int X;
    cin >> X;
    cout << ((X >=3 && X <= 7 && X % 2) ? "YES" : "NO") << endl;
    return 0;
}