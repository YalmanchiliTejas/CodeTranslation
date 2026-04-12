#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, hm = -1, ans = 0;
    cin >> n;
    for(int i=0;i<n;++i){
        int h;
        cin >> h;
        if(h >= hm) ++ans;
        hm = max(h, hm);
    }
    cout << ans << endl;
    
    return 0;
}