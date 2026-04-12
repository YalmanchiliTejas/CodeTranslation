#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int h[30];
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    int maxh = h[0], ans = 1;
    for(int i = 1; i < n; i++){
        if(h[i] >= maxh){
            ans++;
            maxh = h[i];
        }
    }
    cout << ans;
    return 0;
}