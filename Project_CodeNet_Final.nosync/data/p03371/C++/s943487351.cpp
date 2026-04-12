//Half and Half
#include <iostream>
using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int t;
    int T;
    if((a+b)<=c*2){
        cout << a*x+b*y << endl;
    }
    else{
        if(x>=y){
            t= y*c*2+(x-y)*a;
            T= x*c*2;
        }
        else if(x<y){
            t= x*c*2+(y-x)*b;
            T= y*c*2;
        }
        cout << min(t,T) << endl;

    }

}