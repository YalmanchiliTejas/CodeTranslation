#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v)
{
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        cout << v[i] << " \n"[i == sz - 1];
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;cin>>n;
    map<ll,ll> ret;
    for(int i=0;i<n;i++)
    {
        ll a;cin>>a;
        if(a!=1)ret[a] += a;
        for(int j=2;j*j<=a;j++)
        {
            if(a%j) continue;
            ret[j] += a;
            if(j*j!=a) ret[a/j] += a;
        }
    }
    ll ma = 0;
    for(auto p:ret) ma = max(ma, p.second);
    cout << ma << endl;
}

