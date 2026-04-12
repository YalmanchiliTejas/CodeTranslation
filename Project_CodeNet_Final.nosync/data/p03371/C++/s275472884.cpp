#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    // 2*a + c >= 2*x
    // 2*b + c >= 2*y
    int max_c = max(x, y)*2;
    int ret = 1000000000;
    for(int i = 0; i <= max_c; i+=2)
    {
        int temp = c * i;
        if (x-i/2 > 0)
            temp += (x-i/2) * a;
        if (y-i/2 > 0) {
            temp += (y-i/2) * b;
        }
        if (temp < ret)
            ret = temp;
    }
    
    cout << ret << endl;
    return 0;
}