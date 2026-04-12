#include <iostream>
using namespace std;
/* にゃーん  */


int main(){
    int a,b,c,x,y,z=0,ans = 0;
    cin >> a >> b >> c >> x >> y;
    if((a+b) > c*2){
        int max = 0;
        if(x>y){
            max = x;
        }else{
            max = y;
        }
        int ans_ = max*2* c;
        while(x>0&&y>0){
            x--;
            y--;
            z+=2;
        }
        ans = c*z+a*x+b*y;
        if(ans>ans_){
            ans = ans_;
        }
    }else{
        ans = a*x + b*y;
    }
    

    cout << ans << endl;
    return 0;
}