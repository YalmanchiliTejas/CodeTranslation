#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n+10,0);
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    int ans = 0;
    int ma = 0;
    for(int i = 1; i <= n; i++){
        if(ma <= h[i]){
            ans++;
        }
        ma = max(ma,h[i]);
    }
    cout << ans << endl;
}