#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans1, ans2, ans3;
    ans1 = min(x, y) * c * 2;
    if (x < y) {
        ans1 += (y - x) * b;
    } else {
        ans1 += (x - y) * a;
    }
    ans2 = x * a + y * b;
    ans3 = max(x, y) * c * 2;
    cout << min(ans1, min(ans2, ans3)) << endl;
    return 0;
}