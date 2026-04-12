//============================================================================
// Name        : competitive_programing.cpp
// Author      : .Data_Nerd.
// Description : problem solving training
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#define Data_Nerd ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define files freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define mod 1000000007
#define OO 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector <int> rep, sz;

int numOfCon;

int findu(int u){
    return (rep[u] == u) ? u : rep[u] = findu(rep[u]);
}

void join(int a, int b){
    a = findu(rep[a]);
    b = findu(rep[b]);
    if(a == b)
        return;
    if(sz[a] < sz[b])
        swap(a, b);
    rep[b] = a;
    sz[a] += sz[b];
    --numOfCon;
}

struct edge{
    pair<ll, ll> from, to;
};

int main() {
    Data_Nerd

    ll n; cin >> n;

    vector <pair<ll, ll>> sx, sy;

    map <pair<ll, ll>, ll> mp;

    for(int i = 0; i < n; ++i){
        ll a, b; cin >> a >> b;
        sx.push_back({a, b});
        sy.push_back({b, a});
        mp[{a, b}] = i;
    }

    sort(sx.begin(), sx.end());
    sort(sy.begin(), sy.end());

    map<ll, vector<edge>> mpp;

    for(int i = 0; i < n - 1; ++i){
        pair<ll, ll> fromx = {sx[i].first, sx[i].second};
        pair<ll, ll> tox = {sx[i + 1].first, sx[i + 1].second};
        pair<ll, ll> fromy = {sy[i].second, sy[i].first};
        pair<ll, ll> toy = {sy[i + 1].second, sy[i + 1].first};
        mpp[abs(sx[i].first - sx[i + 1].first)].push_back({fromx, tox});
        mpp[abs(sy[i].first - sy[i + 1].first)].push_back({fromy, toy});
    }

    rep.resize(n + 1);
    sz.resize(n + 1);

    for(int i = 1; i <= n; ++i)
        rep[i] = i, sz[i] = 1;

    ll res = 0;

    for(auto i : mpp){
        for(int j = 0; j < i.second.size(); ++j){
            pair<ll, ll> from(i.second[j].from), to(i.second[j].to);
            if(findu(mp[from]) == findu(mp[to]))
                continue;
            join(mp[from], mp[to]);
            res += i.first;
        }
    }

    cout << res << endl;

    return 0;
}
