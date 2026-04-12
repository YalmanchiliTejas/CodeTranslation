#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,M=0,ans=0;
    cin >> n;
    for(int i = 0;i < n;i ++){
        int h;
        cin >> h;
        M = max(h,M);
        if(h>=M) ans ++;
    }
    cout << ans << endl;
    return 0;
}