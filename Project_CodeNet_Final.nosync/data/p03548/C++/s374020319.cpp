#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    
    int ans;
    ans = x/(y+z);
    if(x%(y+z)>=z){
        cout << ans << endl;
    }
    else
        cout << ans-1 << endl;
}
