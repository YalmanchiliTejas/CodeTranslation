#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <tuple>
#include <deque>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <utility>
#include <complex>
#include <functional>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = (1 << 28);
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
int n, m;
vector<int> G[8];
void add_edge(int from, int to){
    G[from].push_back(to);
    G[to].push_back(from);
}
int dfs(int now,vector<bool> used, int count){
    if(count==n-1){
        return 1;
    }
    int ans=0;
    used[now]=true;
    for(int i=0;i<G[now].size();i++){
        if(used[G[now][i]]==true)continue;
        ans+=dfs(G[now][i],used,count+1);
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>m;
    for (int i = 0; i < m; i++)
    {
        int temp, temp1;
        cin >> temp>>temp1;
        add_edge(temp-1,temp1-1);
    }
    vector<bool> used(n,false);
    cout << dfs(0,used,0) << "\n";
}
