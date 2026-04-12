#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>

using namespace std;

#define ll long long

int relu(int a){
    if(a > 0){
        return a;
    }else{
        return 0;
    }
}

int main(void){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = a*x + b*y;

    int z = 2;
    while(x-z/2 > -1 || y-z/2 > -1){
        //cout <<  relu(x-z/2)*a + relu(y-z/2)*b + z*c << endl;
        ans = min(ans, relu(x-z/2)*a + relu(y-z/2)*b + z*c);

        z += 2;
    }

    cout << ans << endl;

    return 0;
}