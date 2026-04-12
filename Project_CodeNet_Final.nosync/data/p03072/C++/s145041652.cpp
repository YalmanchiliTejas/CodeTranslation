#include"bits/stdc++.h"
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep3(i,m,n) for(int (i)=m;(i)<=(n);(i)++)
#define rep3rev(i,m,n) for(int (i)=m;(i)>=(n);(i)--)
#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using P = pair<int, int>;

void Main() {
    int n; cin >> n;
    vi h(n), mx(n); 

    int cnt = 0;
    
    rep(i, n) {
        cin >> h[i];
        if(i == 0) mx[i] = h[i];
        else {
            mx[i] = max(mx[i-1], h[i]);
        }
        if(mx[i] <= h[i]) cnt++;
    }

    cout << cnt << endl;
    
    return;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}