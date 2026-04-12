#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <limits>
using namespace std;

int main(void){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = a*x + b*y;
    int MIN = min(x,y);
    int MAX = max(x,y);
    ans = min(ans, c*MIN*2 + a*(x-MIN) + b*(y-MIN));
    ans = min(ans, c*MAX*2);
    cout << ans << endl;
    return 0;
}