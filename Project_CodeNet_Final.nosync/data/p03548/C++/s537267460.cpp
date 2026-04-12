#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;



int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    int ans;
    ans = x/(y+z);
    if((y+z)*ans+z > x) cout << ans-1 << endl;
    else cout << ans << endl;
    return 0;
}