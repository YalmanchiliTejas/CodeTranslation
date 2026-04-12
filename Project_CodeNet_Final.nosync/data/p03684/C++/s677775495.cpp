#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1000000007;

vector<P> xy;
set<P> sxi, syi;
vector<bool> used;
set<P> edges;

void add_edge(int i){
    auto it = sxi.upper_bound(P(xy[i].first, i));
    if(it != sxi.end()){
        int ni = it->second;
        edges.emplace(min(abs(xy[ni].first - xy[i].first), abs(xy[ni].second - xy[i].second)), ni);
    }
    if(it != sxi.begin()){
        auto nit = next(it, -1);
        int ni = nit->second;
        edges.emplace(min(abs(xy[ni].first - xy[i].first), abs(xy[ni].second - xy[i].second)), ni);
    }
    it = syi.upper_bound(P(xy[i].second, i));
    if(it != syi.end()){
        int ni = it->second;
        edges.emplace(min(abs(xy[ni].first - xy[i].first), abs(xy[ni].second - xy[i].second)), ni);
    }
    if(it != syi.begin()){
        auto nit = next(it, -1);
        int ni = nit->second;
        edges.emplace(min(abs(xy[ni].first - xy[i].first), abs(xy[ni].second - xy[i].second)), ni);
    }
}

int main(){
    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        int x, y;
        cin >> x >> y;
        xy.emplace_back(x, y);
        sxi.emplace(x, i);
        syi.emplace(y, i);
    }

    used.assign(N, false);

    sxi.erase(P(xy[0].first, 0));
    syi.erase(P(xy[0].second, 0));
    add_edge(0);
    used[0] = true;

    int count = 1;
    ll ans = 0;
    while(count < N){
        auto it = edges.begin();
        P p = *it;
        edges.erase(it);
        if(used[p.second]) continue;
        used[p.second] = true;
        ans += p.first;
        sxi.erase(P(xy[p.second].first, p.second));
        syi.erase(P(xy[p.second].second, p.second));
        add_edge(p.second);
        count++;
    }

    cout << ans << endl;

    return 0;
}