#include <bits/stdc++.h>
using namespace std;

using ll = long long;

auto small_cmp = [](const pair<ll, ll>& a, const pair<ll, ll>& b){
    return min(a.first, a.second) < min(b.first, b.second); };
auto big_cmp = [](const pair<ll, ll>& a, const pair<ll, ll>& b){
    return max(a.first, a.second) < max(b.first, b.second); };
pair<ll, ll> normalize(const pair<ll, ll>& p){
    return minmax(p.first, p.second); }

ll solve_with_fixed_small_y_large_x(const ll small_y, const ll large_x, ll an_x, ll an_y, vector<pair<ll, ll>> v){
    for(auto x : v){
        if(x.first < x.second) swap(x.first, x.second);
        an_x = min<ll>(an_x, x.first);
        an_y = max<ll>(an_y, x.second); }
    //cout <<  (large_x - an_x) * (an_y - small_y) << endl;
    return (large_x - an_x) * (an_y - small_y); }

ll solve_with_fixed_small_y_large_y(const ll small_y, const ll large_y, ll st, ll dr, vector<pair<ll, ll>> v){
    //cout << small_y << ' ' << large_y << ' ' << st << ' ' << dr << endl;
    transform(begin(v), end(v), begin(v), &normalize);
    map<ll, vector<ll>> evenimente;
    evenimente[st+1].push_back((ll)1e9 + 1000);
    evenimente[st].push_back(-1);
    evenimente[0].push_back(dr);
    for(const auto x : v){
        evenimente[0].push_back(x.first);
        evenimente[x.first].push_back(-1);
        evenimente[x.first + 1].push_back(x.second);
        evenimente[x.second].push_back(-1);
        evenimente[x.second + 1].push_back((ll)1e9 + 1000); }
    ll cur_dr = dr, rez = (ll)1e9 * (ll)1e9;
    for(auto& x : evenimente){
        for(const auto y : x.second) cur_dr = max(cur_dr, y);
        if(cur_dr > 1e9) break;
        //cout << x.first << ' ' << cur_dr << endl;
        rez = min(rez, cur_dr - x.first); }

    //cout << '@' << rez * (large_y - small_y) << endl;
    return rez * (large_y - small_y); }


ll solve_with_fixed_small_y(const ll an_x, const ll small_y, vector<pair<ll, ll>> v){
    if(all_of(begin(v), end(v), [&](const pair<ll, ll>& p){
        return p.first <= an_x && p.second <= an_x; })){
        return solve_with_fixed_small_y_large_x(small_y, an_x, an_x, small_y, v); }
    auto big = *max_element(begin(v), end(v), big_cmp);
    v.erase(max_element(begin(v), end(v), big_cmp));
    big = normalize(big);

    ll rez = solve_with_fixed_small_y_large_x(small_y, big.second, an_x, big.first, v);

    rez = min<ll>(rez, solve_with_fixed_small_y_large_y(small_y, big.second,
        min<ll>(big.first, an_x), max<ll>(big.first, an_x), v));
    return rez; }
 
int main(){
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for(auto& x : v) cin >> x.first >> x.second;
    if(n == 1){
        cout << 0 << endl;
        return 0; }

    auto small = *min_element(begin(v), end(v), small_cmp);
    v.erase(min_element(begin(v), end(v), small_cmp));
    small = normalize(small);

    cout << solve_with_fixed_small_y(small.second, small.first, v) << endl;
    return 0; }
