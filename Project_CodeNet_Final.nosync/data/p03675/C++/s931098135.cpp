#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(x) x.begin(),x.end()
const ll INF = (1LL<<60);
const int MOD = 1000000007;


deque<int> Push(vector<int> &v){
    deque<int> res;
    int n = v.size();
    rep(i,n){
        if(i % 2) res.push_back(v[i]);
        else res.push_front(v[i]);
    }
    if(n % 2 == 0) reverse(all(res));
    return res;
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    deque<int> ans = Push(a);
    for(auto it : ans) cout << it << " ";
    cout << endl;
}