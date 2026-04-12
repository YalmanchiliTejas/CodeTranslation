#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include<bits/stdc++.h>
#define F first
#define S second
#define vec vector
#define ms multiset
#define pb push_back
#define pll pair<ll,ll>
#define pdd pair<ld, ld>
#define pq priority_queue
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, int>
#define pnn pair<Node*, Node*>
#define uid uniform_int_distribution
#define FILE ifstream in("board.in");ofstream out("board.out");
#define fast cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);cout.sync_with_stdio(0);
using namespace std;
typedef string str;
typedef long long ll;
typedef long double ld;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count()); //uid<int> u1(5, 10); u1(rnd);

int main() {
    fast;
    ll a; cin>>a;
    multiset<ll> s;
    for(int q=0; q<a; q++){
        ll x; cin>>x;
        if(s.size()==0){
            s.insert(x);
            continue;
        }
        auto it = s.lower_bound(x);
        if(it==s.begin()){
            s.insert(x);
            continue;
        }
        it--;
        s.erase(it);
        s.insert(x);
    }
    cout<<s.size();
}