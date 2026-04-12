#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    int t=min(x, y);
    int ans=min((a+b)*t, 2*c*t);
    int s=x>y ? a : b;
    t=max(x, y)-t;
    ans+=min(t*s, 2*c*t);
    cout << ans << endl;
    return 0;
}
