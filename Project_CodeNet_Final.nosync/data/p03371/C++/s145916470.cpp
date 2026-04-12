
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
 
#define rep(i,n) for(ll i=0;i<(n;i++)
typedef long long ll;
using namespace std;

int main(void){
    // Your code here!
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int pizza = 0;
    if(C*2 <= A){
        if(C*2 <= B){
            pizza = 0;
        }
        else{
            pizza = 1;
        }
    }
    else if(C*2 <= B){
        pizza = 2;
    }
    else if(C*2 <= A+B){
        pizza = 3;
    }
    else{
        pizza = 4;
    }
    int ans  = 0;
    if (pizza == 0){
        if(X>Y){
            ans = 2*X*C;
        }
        else{
            ans = 2*Y*C;
        }
    }
    else if(pizza == 1){
        if(X>=Y){
            ans = 2*X*C;
        }
        else{
            ans = 2*X*C + (Y-X)*B;
        }
        
    }
    else if(pizza == 2){
        if(Y>=X){
            ans = 2*Y*C;
        }
        else{
            ans = 2*Y*C + (X-Y)*A;
        }
    }
    else if(pizza == 3){
        if(X>=Y){
            ans = 2*Y*C + (X-Y)*A;
        }
        else{
            ans = 2*X*C + (Y-X)*B;
        }
    }
    else if(pizza == 4){
        ans = A*X + B*Y;
    }
    cout << ans << endl;
}