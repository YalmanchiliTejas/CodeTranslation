#include<bits/stdc++.h>
using namespace std;

int main(){
    while(1){
        int n, l, r; cin >> n >> l >> r;
        if(!n) break;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int ans = 0;
        for(int x = l; x <= r; x++){
            int i;
            for(i = 1; i <= n; i++){
                if(x % a[i - 1] == 0){
                    break;
                }
            }

            ans += (i % 2 == 1);

        }

        cout << ans << endl;
    }

    return 0;
}
