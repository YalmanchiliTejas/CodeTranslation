#include<iostream>
#include<climits>
using namespace std;
int main(){
    int a,b,c,x,y;
    int ans=0;
    cin >> a >> b >> c >> x >> y;

    ans = a * x + b * y;

    if(x > y){
        if(ans > 2 * x * c){
            ans = 2*x*c;
        }
        if(ans > 2*y*c + (x-y) * a){
            ans = 2*y*c + (x-y) * a;
        }
    }else{
        if(ans > 2 * y * c){
            ans = 2*y*c;
        }
        if(ans > 2*x*c + (y-x) * b){
            ans = 2*x*c + (y-x) * b;
        }
    }

    cout << ans << endl;
    return 0;
}