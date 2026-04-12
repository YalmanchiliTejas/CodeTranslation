#include <bits/stdc++.h>


using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

int p = 1000000007;


int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=p) s-=p;
    return s;
}

int sub(int a, int b) {
    int s = (a+p-b);
    if (s>=p) s-=p;
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}

struct DSU {
    vector<int> sz;
    vector<int> parent;

    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    DSU(int n) {
        sz.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) make_set(i);
    }
};

/*const int N = 1200000;

vector<int> facs(N), invfacs(N);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<N; i++) facs[i] = mul(facs[i-1], i);
    invfacs[N-1] = inv(facs[N-1]);
    for (int i = N-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}*/

vector<pair<int, pair<int, int>>> edges;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<pair<pair<int, int>, int>> a(n);

    for (int i = 0; i<n; i++)
    {
        cin>>a[i].first.first>>a[i].first.second; a[i].second = i;
    }

    sort(a.begin(), a.end());
    for (int i = 0; i<n-1; i++) edges.push_back(mp(abs(a[i].first.first - a[i+1].first.first), mp(a[i].second, a[i+1].second)));

    for (int i = 0; i<n; i++) swap(a[i].first.first, a[i].first.second);

    sort(a.begin(), a.end());
    for (int i = 0; i<n-1; i++) edges.push_back(mp(abs(a[i].first.first - a[i+1].first.first), mp(a[i].second, a[i+1].second)));

    sort(edges.begin(), edges.end());

    DSU dsu(n);

    ll res = 0;
    for (auto it: edges)
    {
        if (dsu.find_set(it.second.first)!=dsu.find_set(it.second.second))
        {
            res+=it.first;
            dsu.union_sets(it.second.first, it.second.second);
        }
    }
    cout<<res;




}

