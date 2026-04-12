#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int tot = 0;
    if(2*c <= a + b){
        tot += 2*c*min(x, y);
        if(x > y){
            x -= y;
            tot += min(2*c*x, a*x);
        }
        else if(y > x){
            y -= x;
            tot += min(2*c*y, b*y);
        }
    }
    else tot += a*x + b*y;
    cout << tot << endl;
    return 0;
}
