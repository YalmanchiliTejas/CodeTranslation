#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n; i++)
#define all(v) (v).begin(), (v).end()
#define decimal fixed << setprecision(20)
#define fastcin() cin.tie(0);ios::sync_with_stdio(false)
using namespace std;
using LL = long long;
const int INF = 1e9;
const LL LLINF = 1e16;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];

    int ans = 0;
    rep(i, n){
        bool f=false;
        for(int j=i; j>=0; j--){
            if(h[j] > h[i]) f=true;
        }
        if(!f) ans++;
    }
    cout << ans << endl;

}
