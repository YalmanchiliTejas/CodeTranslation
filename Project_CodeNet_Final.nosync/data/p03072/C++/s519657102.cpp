#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int h[20];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> h[i];

    int sol = 1;
    for (int i = 1; i < n; ++i)
    {
        bool g = true;
        for (int j = 0; j < i; ++j)
            if (h[j] > h[i])
                g = false;
        sol += g;
    }
    cout << sol;
}
