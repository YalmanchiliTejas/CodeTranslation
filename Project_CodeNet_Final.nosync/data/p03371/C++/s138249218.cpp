#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int a,b,c,x,y,xy,xi,yi;
    long long ans,answer;
    cin >> a >> b >> c >> x >> y;
    answer = a*x+b*y;
    if(x>y) xy=x;
    else xy = y;
    rep(i,2*xy+1){
        if(i%2==0){
            xi=a*(x-i/2);
            yi=b*(y-i/2);
            if(xi<0) xi=0;
            if(yi<0) yi=0;
            ans = xi+yi+c*i;
            // cout << ans<<endl;
            if(ans<answer) answer = ans;
        }
    }
    cout<<answer<<endl;

}