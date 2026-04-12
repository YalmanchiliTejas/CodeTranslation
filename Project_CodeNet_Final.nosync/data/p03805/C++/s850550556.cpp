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

int n, m;
int edge[100][100];

int main(void)
{
    cin >> n >> m;
    long long ans = 0;
    int array[n - 1];
    REP(i, n - 1)
    {
        array[i] = i + 2;
    }

    REP(i, m)
    {
        int a, b;
        cin >> a >> b;
        edge[a][b] = 1;
        edge[b][a] = 1;
    }

    do
    {
        bool flag = true;
        if (edge[1][array[0]] == 0)
            flag = false;
        REP(i, n - 2)
        {
            if (edge[array[i]][array[i + 1]] == 0)
                flag = false;
        }
        if (flag)
            ans++;
    } while (next_permutation(array, array + n - 1));

    cout << ans << endl;
}
