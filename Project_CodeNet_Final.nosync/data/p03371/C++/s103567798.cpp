#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    cout << min(a*x + b*y, min(c*2*min(x, y) + ((x < y) ? b*(y-x) : a*(x-y)), c*2*max(x, y))) << endl;
}
