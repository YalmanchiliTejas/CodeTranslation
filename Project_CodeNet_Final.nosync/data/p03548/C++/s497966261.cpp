#include<bits/stdc++.h>
using namespace std;
int main(){
    int x, y, z, ans=1;
    cin >> x >> y >> z;
    x -= y+2*z;
    ans += x/(y+z);
    cout << ans<<endl;
}

