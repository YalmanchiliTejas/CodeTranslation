#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <utility>
#include <stack>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include <sstream>
#define popcount(x) __builtin_popcount(x)
#define oddparity(x) __builtin_parity(x)
#define clz(x) __builtin_clz(x)
#define ctz(x) __builtin_ctz(x)
#define sf scanf
#define pf printf
#define ll long long int
using namespace std;

int i, j, n, a[26];
string s, ans;
vector<int>v[26];

int main()
{
    sf("%d", &n);
    for (i = 0; i < n; i++) {
        cin >> s;
        memset(a, 0, sizeof(a));
        for (j = 0; j < s.size(); j++) {
            a[s[j]-'a']++;
        }
        for (j = 0; j < 26; j++) v[j].push_back(a[j]);
    }
    for (i = 0; i < 26; i++) {
        n = *min_element(v[i].begin(), v[i].end());
        for (j = 0; j < n; j++) ans += ('a'+i);
    }
    cout << ans << endl;
    return 0;
}