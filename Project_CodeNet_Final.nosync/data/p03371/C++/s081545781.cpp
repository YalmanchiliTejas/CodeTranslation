#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int ans=1e9, z;
    z = max(x,y);
    for(int i=0;i<=2*z;i++){
        int ab = a*max(0, x-i) + b*max(0,y-i) + i*2*c;
        ans = min(ab, ans);
    }
    
    cout << ans << endl;
    return 0;
}
