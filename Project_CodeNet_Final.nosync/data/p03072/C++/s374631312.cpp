#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    int ans = 0;
    for(int i = 1; i < n; i++)
    {
        bool ok = true;
        for(int j = 0; j < i; j++)
        {
            if(h[j] > h[i]) ok = false;
        }
        if(ok) ans++;
    }
    cout << ans + 1 << endl;
    return 0;
}

