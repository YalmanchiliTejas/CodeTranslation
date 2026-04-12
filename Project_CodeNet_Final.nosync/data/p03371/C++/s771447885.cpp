#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
using namespace std;
typedef long long ll;

int main(){

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll ans = 0;
    if( 2*c <= a + b ){
        int temp = min(x, y);
        x -= temp;
        y -= temp;
        
        ans += 2*c*temp;

        if(x == 0){
            if( 2*c <= b ){
                ans += 2*c*y;
            }
            else{
                ans += b*y;
            }
        }
        else if(y == 0){
            if( 2*c <= a ){
                ans += 2*c*x;
            }
            else{
                ans += a*x;
            }
        }
    }
    else{
        ans += x*a + y*b;
    }

    cout << ans;


    return 0;
}