#include <bits/stdc++.h>
using namespace std;

void solve(int n, int l, int r){
        int a[n] = {};
        for(int i=0; i<n; ++i) cin >> a[i];
        int ans = 0;
        for(int i=l; i<=r; ++i){
                bool f = n % 2 == 0;
                for(int j=0; j<n; ++j){
                        if(i % a[j] == 0){
                            f = j % 2 == 0;
                            break;
                        }
                }
                if(f) ++ans;
        }
        cout << ans << "\n";
}

int main(){
//      cin.tie(0);
//      ios::sync_with_stdio(false);
        while(1){
                int n, l, r;
                cin >> n >> l >> r;
                if(n == 0) return 0;
                solve(n, l, r);
        }
}
