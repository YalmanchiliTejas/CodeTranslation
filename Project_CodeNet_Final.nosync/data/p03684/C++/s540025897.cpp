#include <bits/stdc++.h>
using namespace std;

int dist(int a, int b){
    return max(a-b, b-a); }

int dist(pair<int, int> a, pair<int, int> b){
    return min(
        dist(a.first, b.first),
        dist(a.second, b.second)); }

pair<int, int> rev(pair<int, int> a){
    return make_pair(a.second, a.first); }

class merge_find{
    vector<int> tata, rk;
public:
    merge_find(const int n): tata(n), rk(n, 0){
        iota(begin(tata), end(tata), 0); }
    int find(int x){
        return x == tata[x] ? x : tata[x] = find(tata[x]); }
    bool merge(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return false;
        if(rk[x] < rk[y]) swap(x, y);
        if(rk[x] == rk[y]) ++rk[y];
        tata[y] = x;
        return true; } };

int spanning_tree(int n, vector<tuple<int, int, int>> edges){
    merge_find mf(n);
    int rez = 0;
    sort(begin(edges), end(edges));
    for(auto e : edges)
        if(mf.merge(get<1>(e), get<2>(e)))
            rez += get<0>(e);
    return rez; }

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    vector<int> v_(n);
    
    for(auto& x : v) cin >> x.first >> x.second;

    iota(begin(v_), end(v_), 0);

    sort(begin(v_), end(v_), [&v](const int x, const int y){
        return v[x] < v[y]; });

    vector<tuple<int, int, int>> edges;

    for(int i = 0, j = 1; j < n; ++i, ++j)
        edges.emplace_back(
            dist(v[v_[i]], v[v_[j]]),
            v_[i],
            v_[j]);

    sort(begin(v_), end(v_), [&v](const int x, const int y){
        return rev(v[x]) < rev(v[y]); });

    for(int i = 0, j = 1; j < n; ++i, ++j)
        edges.emplace_back(
            dist(v[v_[i]], v[v_[j]]),
            v_[i],
            v_[j]);

    cout << spanning_tree(n, edges) << endl;
    return 0; }
