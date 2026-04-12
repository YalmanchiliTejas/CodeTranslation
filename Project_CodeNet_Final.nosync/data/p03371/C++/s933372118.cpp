#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i) = 0; (i) < (n); (i)++)


int main(){
    int a, b, c, x, y, ans = 0;
    cin >> a >> b >> c >> x >> y;

    ans += 2*c*min(x,y);
    ans += x < y ? b*(y-x) : a*(x-y);

    int extra = 2*c*max(x,y);

    cout << min({a*x + b*y, ans, extra}) << endl;
}

