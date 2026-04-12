#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <set>
#include <cctype>
#include <bitset>
#include <type_traits>

#include <list>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define YES(j) cout << (j ? "YES" : "NO") << endl;
#define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
#define yes(j) std::cout << (j ? "yes" : "no") << endl;
typedef long long ll;

int main(void)
{
    int n;
    cin >> n;
    int a[26];
    fill(a, a + 26, 100000);

    REP(i, n)
    {
        int t[26];
        fill(t, t + 26, 0);
        string s;
        cin >> s;
        REP(j, s.length())
        {
            t[s[j] - 'a']++;
        }
        REP(j, 26)
        {
            a[j] = min(a[j], t[j]);
        }
    }

    REP(i, 26)
    {
        cout << string(a[i], i + 'a');
    }
    cout << endl;
}