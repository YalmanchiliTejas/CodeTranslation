#include<iostream>
#include <string>
#include<vector>
#include<algorithm>
#include <cstdlib>
using namespace std;

int main(){
    int a,b,c,x,y,ans;
    cin >> a >> b >> c >> x >> y ;
    if(a + b <= 2*c){
        ans = a*x + b*y;
        cout << ans << endl;
    }
    else{
        if(x >= y){
            ans = 2*c*y + a*(x-y);
        }
        else{
            ans = 2*c*x + b*(y-x);
        }
        int t = max(x,y);
        t = t*2*c;
        if(t < ans){
            ans = t;
        }
        cout << ans << endl;
    }
    return 0;
}