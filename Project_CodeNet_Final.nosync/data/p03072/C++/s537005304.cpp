#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    int hmax = 0;
    int h;
    for(int i=0; i<n; i++){
        cin >> h;
        if(h >= hmax){
            ans++;
            hmax = h;
        }
    }
    cout << ans << endl;
}