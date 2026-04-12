#include <bits/stdc++.h>
#define rep(i, a) for(int i = 0; i < a; i++)
#define all(v) v.begin(), v.end()
#define dcout cout << fixed << setprecision(15)
#define arep(i, a) for(auto i : a)
#define F first
#define S second
#define VE vector<int>
#define pb(x) push_back(x)
#define MOD 1000000007
#define INF 10000000000
#define int long long
#define KETA(n) floor(log10(n) + 1)
using namespace std;
signed main() {
    char a, b, c;
    cin >> a >> b >> c;
    int n = (b - '0') * 10 + c - '0';
    if(n % 4 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}