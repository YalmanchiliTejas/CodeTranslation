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
#define pii pair<ll,ll>

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


using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    
    vector<ll> v(n);
    bool odd = n % 2 == 1;
    for(int i = 0;i < n;i++)
    {
        int c = n/2;
        int p = (i+1)/2;
        if(i == 0)
        {
            p = 0;
        }
        bool codd = i % 2 == 1;
        if(codd ^ odd)
        {
            p *= -1;
        }
        //cout << c + p << " " << a[i] << endl;
        v[c+p] = a[i];
    }
    for(auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}