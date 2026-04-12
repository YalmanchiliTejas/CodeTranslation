#include<bits/stdc++.h>

using namespace std;

const int N = 10000 + 5;
const int INF = 0x3f3f3f3f;
using LL = long long;
using P = pair<int, int>;
map<int, int> mp;
set<int> S;

int a[N];

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = INT_MAX;
    int tmp = max(x, y);
    ans = min(ans, tmp * 2 * c);
    
    ans = min(ans, x * a + y * b);

    if(x >= y){
        int sum = y * 2 * c + (x - y) * a;
        ans = min(ans, sum);
    }else{
        int sum = x * 2 * c + (y - x) * b;
        ans = min(ans, sum);
    }
    cout << ans << endl;
}
