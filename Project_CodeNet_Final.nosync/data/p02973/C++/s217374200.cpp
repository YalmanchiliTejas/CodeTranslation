#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
const ll mod = 1000000007;


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> v;
    auto comp = [](int a, int b) {
        return a>b;
    };
    rep(i, n) {
        if (v.size()==0) {
            v.push_back(a[i]);
            continue;
        }
        if (a[i]<=v.back()) {
            v.push_back(a[i]);
        }
        else {
            auto it = upper_bound(v.begin(), v.end(), a[i], comp);
            *it = a[i];
        }
    }
    int ans = v.size();
    
    
    
    cout << ans << endl;
    return 0;
}
