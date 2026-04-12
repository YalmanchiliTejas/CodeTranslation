#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int ma = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(ma <= a[i]) ans++;
        ma = max(ma, a[i]);
    
    }
    cout << ans << endl;
    return 0;
}