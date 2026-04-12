#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<ll, ll> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

struct Point{
    int xi;
    int yi;
    int id;
    bool operator<(const Point &T) const{
        return xi<T.xi;
    }
};

struct Dist{
    int dis;
    int i1;
    int i2;
    bool operator<(const Dist &D) const {
        return dis < D.dis;
    }
};

const int N = (int)1e5 + 9;

int pi[N];
int sz[N];

int fin(int u){
    if(pi[u]==u)
        return u;
    return pi[u]=fin(pi[u]);
}

bool merge(int a, int b){
    a=fin(a);
    b=fin(b);
    if(a==b)
        return false;
    if(sz[a] > sz[b])
        swap(a, b);
    sz[b] += sz[a];
    pi[a] = b;
    return true;
}

int main(){
    fastIO;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ )pi[i] = i, sz[i] = 1;
    vector<Point> xx, yy;
    int x, y;
    for(int i = 1; i <= n; i ++ ){
        cin >> x >> y;
        xx.push_back({x,y,i});
        yy.push_back({y,x,i});
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    vector<Dist> dd;
    for(int i = 1; i < n; i ++ ){
        dd.push_back({xx[i].xi - xx[i-1].xi, xx[i-1].id, xx[i].id});
        dd.push_back({yy[i].xi - yy[i-1].xi, yy[i-1].id, yy[i].id});
    }
    int res = 0;
    sort(dd.begin(), dd.end());
    for(int i = 0; i < dd.size(); i ++ ){
        if(merge(dd[i].i1, dd[i].i2))
            res += dd[i].dis;
    }
    cout << res << "\n";
    return 0;
}