#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    deque<int> d;
    rep(i,n){
        int p = lower_bound(ALL(d),a[i]) - d.begin();
        if(p == 0){
            d.push_front(a[i]);
        }else d[p-1] = a[i];
    }
    int ans = d.size();
    cout << ans << endl;
    return 0;
}