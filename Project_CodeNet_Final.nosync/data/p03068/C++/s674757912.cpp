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
#include <cassert>
using namespace std;
using ll = long long;
const int INF = 1<<30;
const int MOD = 1e9 + 7;
signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    int k; cin >> k;
    k--;
    char ch = s[k];
    for(int i = 0; i < n; i++)
    {
        if(ch != s[i]) s[i] = '*';
    }
    cout << s << endl;
    return 0;
}

