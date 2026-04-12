#include <iostream>

using namespace std;

int main(){
    int a,b,ab,x,y;
    cin >> a >> b >> ab >> x >> y;
    int cost=0;
    if(ab*2<a+b){
        cost+=(ab*2)*min(x,y);
        if(x>y){
            if (ab*2<a){
                cost+=abs(x-y)*ab*2;
            }else{
                cost+=abs(x-y)*a;
            }
        }else{
            if (ab*2<b){
                cost+=abs(x-y)*ab*2;
            }else{
                cost+=abs(x-y)*b;
            }
        }
    }else{
        cost=a*x+b*y;
    }
    cout << cost << endl;
    return 0;
}