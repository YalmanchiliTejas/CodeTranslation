#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x-I .)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    ll N, X, M;
    cin >> N >> X >> M;
    if(N == 1){
        cout << X << endl;
        return 0;
    }
    vector<ll> f;
    set<ll> al;
    f.push_back(X); al.insert(X);
    bool is_zero = false;
    ll last = 0;
    while(true){
        ll nxt = (f[f.size()-1] * f[f.size()-1]) % M;
        if(nxt == 0)is_zero = true;
        if(al.count(nxt) == 1){last = nxt; break;}
        f.push_back(nxt); al.insert(nxt);
    }
    if(is_zero){
        ll ans = 0;
        for(ll i = 0; i < min(N, (ll)f.size()); ++i)ans += f[i];
        cout << ans << endl;
        return 0;
    }
    ll ans = 0;
    bool out_head = false;
    ll loop_len = 0;
    ll loop_sum = 0;
    ll rest = N;
    vector<ll> loop;
    for(int i = 0; i < min(N, (ll)f.size()); ++i){
        if(f[i] == last)out_head = true;
        if(!out_head){
            ans += f[i];
            --rest;
        }else{
            ++loop_len;
            loop_sum += f[i];            
            loop.push_back(f[i]);
        }
    }
    ans += rest / loop_len * loop_sum;
    rest %= loop_len;
    rep(i,rest)ans += loop[i];
    cout << ans << endl;
    return 0;
}