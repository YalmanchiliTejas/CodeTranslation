#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define INF 1000000000

int main() {
    int n,ans=0,M=-1;
    cin >> n;
    vector<int> H(n);
    rep(i,n) cin >> H.at(i);
    rep(i,n){
        ans += int(M<=H.at(i));
        M = max(M,H.at(i));
    }
    cout << ans << endl;
}