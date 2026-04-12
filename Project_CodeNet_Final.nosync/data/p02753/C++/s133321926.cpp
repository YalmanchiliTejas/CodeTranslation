#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define yes "Yes"
#define yse "Yes"
#define no "No"

#define pb push_back
#define rep(i, l, n) for (int i = (l); i < n; i++)
#define rep_cs(i, l, n) for (int i = (l); i <= n; i++)
#define rep_d(j, n) for (int j = n; j >= 0; j--)
#define rep_d_op(j, n, a) for (int j = n; j >= a; j--)

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}

const int MOD = 1000000007;
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};
const ll INF = 1LL << 60;

// int max = *std::max_element(vec.begin(), vec.end());
// int sum = accumulate(list, list + size, 0);

int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }

using Graph = vector<vector<int>>;
Graph G;
vector<bool> seen;
void dfs(const Graph &G, int v)
{
    seen[v] = true;

    for (auto next_v : G[v])
    {
        if (seen[next_v])
            continue;
        dfs(G, next_v);
    }
}

int main()
{
    string s;
    cin >> s;
    if (s[0] == s[1] && s[1] == s[2])
    {
        cout << no << endl;
    }
    else
    {
        cout << yes << endl;
    }
}