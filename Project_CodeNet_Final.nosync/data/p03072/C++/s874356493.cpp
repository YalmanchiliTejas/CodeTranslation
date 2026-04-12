#include <bits/stdc++.h>
using namespace std;
int main(){

    int n = 0, prev = 0;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x = 0;
        cin >> x;
        if( i > 0){
            if(x >= prev){
                ans++;
            }
        }
        prev = max(prev, x);
    }
    ans++;
    cout << ans << "\n";
   return 0;
}