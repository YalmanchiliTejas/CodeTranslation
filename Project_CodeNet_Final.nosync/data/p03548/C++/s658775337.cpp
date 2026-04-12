#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    x -= z*2;
    int ans = x/y;
    int num_z = ans - 1;

    for (size_t i = 0; i < x/y; i++)
    {
        if(x/(y*ans+num_z*z) >= 1) break;
        else {
            ans--;
            num_z = ans -1;
            }
    }
    cout << ans << endl;
    return 0;
}