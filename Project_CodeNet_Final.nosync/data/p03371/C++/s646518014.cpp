#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int c1 = a*x + b*y;
    int c2 = 2*c*min(x,y) + ((x<y)?(y-x)*b:(x-y)*a);
    int c3 = 2*c*max(x,y);
    //printf("%d %d %d\n",c1,c2,c3);
    cout << min(c1, min(c2, c3));
}
