#include <bits/stdc++.h>
#define em3 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define X real()
#define Y imag()
#define cross(a, b) ((conj(a) * (b)).Y)
#define dot(a, b) ((conj(a) * (b)).X)
#define EPS 1e-7
long long mod = 1e9 + 7;
const int N = 2e5 + 5;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const double pi = acos(-1);
typedef complex <double> point;
typedef tuple<int, int, int> line;
typedef vector<point> polygon;
///           x , y , index
vector<pair<pair<ll, ll> , ll>> v1 , v2;
///  cost , index1 , index2
map < ll , vector<pair<ll , ll>>> mp;
ll rep[N], sz[N], n, nc, m, ans;
int fnd(int u)
{
    if(rep[u] == u)
        return u;
    else
        u = fnd(rep[u]);
    return u;
}
bool join(int a, int b)
{
    a = fnd(rep[a]);
    b = fnd(rep[b]);
    if(a == b)
        return true ;
    if(sz[a] < sz[b])
        swap(a, b);
    sz[a] += sz[b];
    rep[b] = a;
    nc--;
    return false;
}
int main()
{
    em3
    cin >> n ;
    nc = n;
    for(int i = 0 ; i < n ; i++)
        sz[i] = 1, rep[i] = i;
    for(int i = 0 ; i < n ; i++)
    {
        pair<ll , ll > a ;
        cin >> a.first >> a.second;
        v1.push_back({a , i});
        v2.push_back({{a.second , a.first} , i});
    }
    sort(v1.begin() , v1.end());
    sort(v2.begin() , v2.end());
    for(int i = 0 ; i < n - 1 ; i++)
    {
        mp[abs(v1[i].first.first - v1[i + 1].first.first)].push_back({v1[i].second , v1[i + 1].second});
        mp[abs(v2[i].first.first - v2[i + 1].first.first)].push_back({v2[i].second , v2[i + 1].second});
    }
    for(auto i : mp)
    {
        for(int j = 0 ; j < i.second.size() ; j++)
        if(!join(i.second[j].first , i.second[j].second))
        {
            ///edges.push_back({v[i].second.first, v[i].second.second});
            ans += i.first;
        }
    }
    cout << ans << endl;
    return 0;
}
