#include <bits/stdc++.h>
#define endl '\n'
#define sync_cin                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
using namespace std;

#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;



int main()
{
    sync_cin;
    int n; cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    int ans = 1;
    int maxi = h[0];
    for (int i = 1; i < n; i++)
        if (h[i] >= maxi) 
        {
            ans++;
            maxi = h[i];
        }
    cout << ans << endl;
    return 0;
}