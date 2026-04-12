#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    vector<int> x;
    rep(i,n){
        auto it = upper_bound(x.begin(),x.end(),-a[i]);
        if(it==x.end())x.insert(it,-a[i]);
        else *it = -a[i];
    }
    cout << x.size() << endl;
    return 0;
}
