#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <complex>
#include <cctype>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <iomanip>
#include <limits.h>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cout << i << "\n"

const ll MOD = 1000000007;

//UnionFind 
struct UnionFind
{
    std::vector<ll> uni;
    ll num;
    UnionFind(ll s) : uni(s, -1),num(s) {}

    //頂点aが所属するグループ
    ll root(ll a)
    {
        if (uni[a] < 0)
        {
            return a;
        }
        return uni[a] = root(uni[a]);
    }

    //a,bをつなげる
    bool connect(ll a, ll b)
    {
        a = root(a);
        b = root(b);
        if (a == b)
        {
            return false;
        }

        if (uni[a] > uni[b])
        {
            std::swap(a, b);
        }

        uni[a] += uni[b];
        uni[b] = a;
        return true;
    }

    //a,bが同グループか確認
    bool isConnect(ll a, ll b)
    {
        return root(a) == root(b);
    }

    //aが属するグループの要素数
    ll size(ll a)
    {
        return -uni[root(a)];
    }

    //グループ数を返す
    ll groups()
    {
        std::set<ll> b;
        for (ll i = 0; i < num; i++)
        {
            b.insert(root(i));
        }
        return b.size();
    }
};

struct Edge{ll u,v,cost;};

bool comp(const Edge& e1,const Edge& e2){
    return e1.cost<e2.cost;
}

ll krustal(ll n,std::vector<Edge>& es){
    sort(all(es),comp);
    UnionFind path(n);
    ll res=0,e=es.size();
    rep(i,0,e){
        Edge temp=es[i];
        if(!path.isConnect(temp.u,temp.v)){
            path.connect(temp.u,temp.v);
            res+=temp.cost;
        }
    }
    return res;
}

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    //問題文中の添え字が0-indexか1-indexか確認!

    ll n;
    std::cin >> n;
    std::vector<P> x(n), y(n);
    std::vector<Edge> es;
    rep(i,0,n){
        ll a, b;
        std::cin >> a >> b;
        x[i] = P(a, i);
        y[i] = P(b, i);
    }
    sort(all(x));
    sort(all(y));
    rep(i,1,n){
        es.push_back(Edge{x[i].second,x[i-1].second,x[i].first-x[i-1].first});
        es.push_back(Edge{y[i].second,y[i-1].second,y[i].first-y[i-1].first});
    }

    std::cout<<krustal(n,es);
    return 0;
}