#include <bits/stdc++.h>
using namespace std;
     
#define rep(i,n) for (int i = 0; i < (int)(n);i++)

int main() {
    int A,B,C;
    long long X,Y,buf;
    cin >> A >> B >> C >> X >> Y;
    long long min=X*A+Y*B;
    for(int i=0;i<=X+Y;i++){
        if(i>=X&&i>=Y){
            buf=2*C*i;
        }else if(i<X&&i>=Y){
            buf=2*C*i+A*(X-i);
        }else if(i>=X&&i<Y){
            buf=2*C*i+B*(Y-i);
        }else{
            buf=2*C*i+A*(X-i)+B*(Y-i);
        }
        if(buf<min){
            min = buf;
        }
    }
    cout << min << endl;
}