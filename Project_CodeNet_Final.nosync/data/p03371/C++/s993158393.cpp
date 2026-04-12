#include<iostream>
using namespace std;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    if(a+b<=2*c){
        cout << a*x + b*y;
    }else{
        if(x>y){
            if(a>2*c){
                cout << 2*c*x; 
            }else{
                cout << 2*c*y + a*(x-y);
            }
        }else{
            if(b>2*c){
                cout << 2*c*y;
            }else{
                cout << 2*c*x + b*(y-x);
            }
        }
    }
    cout << endl;
}