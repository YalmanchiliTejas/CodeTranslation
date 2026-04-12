#include <bits/stdc++.h>
#define int long
#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

main() {
    int N; cin >> N; int pos=0; int ans=0;
    rep(i,N){
        int H; cin >> H;
        if(pos<=H){
            ans++; pos=H;
        }
    }
    cout << ans << endl;
    return 0;
}