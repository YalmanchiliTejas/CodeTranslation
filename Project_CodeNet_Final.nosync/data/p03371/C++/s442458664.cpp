#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(),(x).end()
#define Graph vector<vector<int>>;
#define iterG(next_v, G, v) for(auto next_v : G[v]
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int z, ans, tmp;
    //1439
    ans = a * x + b * y;
    repi(i, 1, max(x, y)+1){
        z = 2 * i; // ab
        tmp = a * max(0, (x-i)) + b * max(0, y-i) + c * z;
        ans = min(ans, tmp);
        
        
    }
    cout << ans << endl;
    return 0;
}

