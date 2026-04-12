#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

long long max(long long a, long long b){
    if(a > b){
        return a;
    } else {
        return b;
    }
}

long long min(long long a, long long b){
    if(a < b){
        return a;
    } else {
        return b;
    }
}

int main(){
    long long a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    long long ans = 1000000000;
    for(long long z = 0; z <= max(x, y); z++){
        ans = min(ans, z*2*c + max(0, x-z)*a + max(0, y-z)*b);
    }
    cout << ans << endl;
    return 0;
}
