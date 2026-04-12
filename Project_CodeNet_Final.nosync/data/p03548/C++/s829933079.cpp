#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int ans = 1;
    while(1) {
        if ( y * ans + z * ( ans + 1 ) > x ) break;
        ++ans;
    }
    cout << ans - 1 << endl;
    return 0;
}
