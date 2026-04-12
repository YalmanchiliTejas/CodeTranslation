#include<iostream>
using namespace std;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    long long min= 10000000000;
    for(int i=0;i<=100000;i++){
        long long value = (long long)(2*c*i + max(0,x-i)*a+max(0,y-i)*b);
        if(value<min){
            min = value;
        }
    }
    cout << min << endl;
    /*if(a+b<=2*c){
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
    cout << endl;*/
}