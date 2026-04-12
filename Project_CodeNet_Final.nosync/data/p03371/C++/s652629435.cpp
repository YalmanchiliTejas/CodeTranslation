#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    int minxy = min(2*x,2*y);
    int maxxy = max(2*x,2*y);

    int p = a*x + b*y;
    int q = c*minxy + a*(x-minxy/2) + b*(y-minxy/2);
    int r = c*maxxy;

    //cout << p << " " << q << " " << r << endl;

    cout << min(min(p,q),r) << endl;

}