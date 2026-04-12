#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,n) f2or (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> H(N);
    rep(i,N) cin >> H[i];
    int max = 0;
    int ans = 0;
    rep(i,N){
        if(max <= H[i]) {
            max = H[i];
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
