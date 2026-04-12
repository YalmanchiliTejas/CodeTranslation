#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define rep(i,n) for(int i=0;i<n;i++)
#define all(in) in.begin(), in.end()
#define INF (sizeof(int) == 4 ? (int)1e9:(int)1e18)
#define EPS 0.0000000001
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<typename Head, typename Value> auto vectors(const Head &head, const Value &v) { return vector<Value>(head, v); }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) { auto inner = vectors(tail...); return vector<decltype(inner)>(x, inner); }
signed main(){
    int n; cin >> n;
    vector<int>v(n);
    for(auto & e : v) cin >> e;
    map<int,int>mp;
    int ans = 0;
    reverse(all(v));
    for(int i = 0; i < v.size(); ++i){
        auto itr = mp.upper_bound(v[i]);
        mp[v[i]]++;
        if(itr == mp.end())
            ++ans;
        else{
            mp[itr -> first]--;
            if(mp[itr -> first] == 0) mp.erase(itr);
        }
        
    }
    cout << ans << endl;
}
