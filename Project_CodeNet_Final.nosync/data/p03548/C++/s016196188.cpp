#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MOD 1000000007
#define PI 3.141592653589793

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    x -= 2 * z;
    int ans = 0;
    while(1){
        x -= y;
        if(x >= 0){
            ans++;
            x -= z;
        }else{
            cout << ans << endl;
            return 0;
        }
    }
}
