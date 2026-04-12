#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <iomanip>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <string.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>(N, 1));
    int a, b;
    rep(0, i, M)
    {
        cin >> a >> b;
        a--;
        b--;
        graph.at(a).at(b) = 0;
        graph.at(b).at(a) = 0;
    }
    vector<int> v(N);
    rep(0, i, N)
    {
        v.at(i) = i;
    }

    int ans = 0;
    do
    {
        if (v.at(0))
        {
            break;
        }
        bool flag = true;
        rep(0, i, N - 1)
        {
            if (graph.at(v.at(i)).at(v.at(i + 1)))
            {
                flag = false;
            }
        }
        if (flag)
        {
            ans++;
        }
    } while (next_permutation(all(v)));
    cout << ans << endl;
}