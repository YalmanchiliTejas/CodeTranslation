#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i) = 0; (i) < (n); (i)++)


int main(){
    int x, y, z;
    cin >> x >> y >> z;
    x -= z;
    int ans = 0;
    while(x-y-z >= 0){
        x -= y+z;
        ans++;
    }
    cout << ans << endl;
}
