#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int h[1010];

    for(int i = 0;i < n;i++){
        cin >> h[i];
    }

    int ans = 0;
    for(int i = 0;i < n;i++){
        bool f = true;
        for(int j = 0;j < i;j++){
            if(h[j] > h[i]){
                f = false;
                break;
            }
        }
        if(f) ans++;
    }

    cout << ans << endl;
    return 0;
}