#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

const int Cin()
{
    int n;
    cin >> n;
    return n;
}

const int DFS(const vector<vector<int>> &adList, const int v, const int rem, vector<bool> &hasNotVisited)
{
    // 残り長点数がゼロ＝全ての頂点を回り終えたら＋１する
    if (rem == 0)
    {
        hasNotVisited[v] = true;
        return 1;
    }
    // vに繋がる頂点のうち，未訪問の頂点へ移動
    int ans = 0;
    for (const int u : adList[v])
    {
        if (hasNotVisited[u])
        {
            hasNotVisited[u] = false;
            ans += DFS(adList, u, rem - 1, hasNotVisited);
            hasNotVisited[u] = true;
        }
    }
    return ans;
}

int main()
{
    // 始点が1に固定＆N≤1と小さいので
    // DFSを用いた全探索で間に合う
    int N = Cin(), M = Cin();
    vector<vector<int>> adList(N);
    for (int i = 0; i < M; ++i)
    {
        int ai = Cin() - 1, bi = Cin() - 1;
        adList[ai].push_back(bi);
        adList[bi].push_back(ai);
    }
    // DFS
    vector<bool> hasNotVisited(N, true);
    hasNotVisited[0] = false;
    cout << DFS(adList, 0, N - 1, hasNotVisited) << endl;
}
