#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    //ABピザを2*x枚買うとき
    int aab = max(0,y-x)*b+2*x*c;
    int bab = max(0,x-y)*a+2*y*c;
    int n = min(aab,bab);
    cout << min(a*x+b*y,n) << endl;
    return 0;
}
