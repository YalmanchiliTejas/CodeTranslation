#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <tuple>

using ll = long long;
using namespace std;
#define modmod 1000000007

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,k,n) for(int i=k;i<n;i++)


int main(){
    int A,B,C;
    int X,Y;
    cin >> A >> B >> C >> X >> Y;
    int maxi, mini;
    bool Xbig = false;
    if(X>Y){
        maxi = X;
        mini = Y;
        Xbig = true;
    }else{
        maxi = Y;
        mini = X;
    }

    int result = 0;


    if(2*C < A and 2*C < B){
        result += maxi*2*C;
    }
    else if(2*C < A+B){
        result += 2*C*mini;
        if(Xbig){
            if(A <= 2*C){
                result += A*(maxi-mini);
            }else{
                result += 2*C*(maxi-mini);
            }
        }else{
            if(B <= 2*C){
                result += B * (maxi-mini);
            }else{
                result += 2*C * (maxi-mini);
            }
        }
    }else{
        result += A*X + B*Y;
    }

    cout << result << endl;

    return 0;
}
