#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
using ll = long long;

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    if(a + b > 2*c){
        ans = 2 * c * min(x,y);
        if(x > y){
            if(a > 2*c){
                ans += 2*c*(x-y);
            }else{
                ans += a*(x-y);
            }
        }else{//x<y
            if(b>2*c){
                ans += 2*c*(y-x);
            }else{
                ans += b*(y-x);
            }
        }
    }else{
        ans = x * a + y * b;
    }
    cout << ans << endl;
    return 0;
}