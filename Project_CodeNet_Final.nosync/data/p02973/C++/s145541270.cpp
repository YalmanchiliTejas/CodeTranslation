#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    deque<int> d;
    rep(i,n){
        int t = lower_bound(ALL(d), a[i]) - d.begin();
        if(t == 0) d.push_front(a[i]);
        else d[t-1] = a[i];
    }

    int ans = d.size();
    cout << ans << endl;
}