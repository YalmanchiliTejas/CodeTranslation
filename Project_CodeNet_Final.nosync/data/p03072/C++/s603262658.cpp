#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int n;
    cin >> n;
    int ans = 0, maxi = 0;
    for(int i=0;i<n;++i){
        int h;
        cin >> h;
        if(h >= maxi){
            maxi = h;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
