#include <cmath>
#include <vector>
#include <map>
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
#define ti4 tuple<int,int,int,int>
#define pii pair<ll,ll>
#define REP(x,n) for(int x = 0;x < n;x++)

struct UnionFind {
    vector<ll> data;
    UnionFind(ll size) : data(size, -1) { }
    bool unionSet(ll x, ll y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(ll x, ll y) {
        return root(x) == root(y);
    }
    ll root(ll x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    ll size(ll x) {
        return -data[root(x)];
    }
};

#define MAX_COUNT 1000001

string ss;

vector<int> g[MAX_COUNT];
int vv[MAX_COUNT];
int vmi[MAX_COUNT];
int vma[MAX_COUNT];
int mod[MAX_COUNT];

static const int nv = -10000000;

struct Visit
{
    int from;
    int current;
};

string s[10];
int h,w;

char No = '.';

bool dfs(int x, int y)
{
    if(x == w - 1 && y == h - 1 && s[y][x] != No)
    {
        return true;
    }
    bool c = false;
    {
        if(x < w - 1)
        {
            if(s[y][x + 1] != No)
            {
                c |= dfs(x+1, y);
            }
        }
        if(y < h - 1)
        {
            if(s[y + 1][x] != No)
            {
                c |= dfs(x, y + 1);
            }
        }
    }
    return c;
}

int main()
{
    cin >> h >> w;
    for(int i = 0;i < h;i++)
    {
        cin >> s[i];
    }
    int sum = 0;
    for(int y = 0;y < h;y++)
    {
        for(int x = 0; x < w;x++)
        {
            if(s[y][x] != No)
            {
                sum++;
            }
        }
    }
    if(sum > w + h -1)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    if(s[0][0] == No)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    if(dfs(0,0))
    {
        cout << "Possible" << endl;
        return 0;
    }
    cout << "Impossible" << endl;
    return 0;
}