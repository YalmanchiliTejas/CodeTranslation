#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdint>
#include <climits>
#include <unordered_set>
#include <sstream>

using namespace std;

#define ll long long int
#define pii pair<int,int>
#define ti3 tuple<ll,ll,ll>

struct BIT
{
    std::vector<int> bit;
    
    BIT(int size) : bit(size, 0){ }
    
    void add(int k, int x) {
        while (k < bit.size()) {
            bit[k] += x;
            k += k &-k;
        }
    }
    int sum(int k) {
        int res = 0;
        while (k > 0) {
            res += bit[k];
            k -= k&-k;
        }
        return res;
    }
};

struct UnionFind {
    vector<int> data;
    
    UnionFind(int size) : data(size, -1) { }
    
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y)
        {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

vector<int> g[10];
int n, m;

ll dfs(int p, unordered_set<int> b)
{
    auto s = b.size();
    if(s == n)
    {
        return 1;
    }
    ll sum = 0;
    for(auto e: g[p])
    {
        if(b.find(e) == b.end())
        {
            auto nb = b;
            nb.insert(e);
            sum += dfs(e, nb);
        }
    }
    return sum;
}

int main(void)
{
    cin >> n >> m;
    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    unordered_set<int> d;
    d.insert(1);
    cout << dfs(1, d) << endl;
    return 0;
}