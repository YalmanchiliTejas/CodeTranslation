#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main(void){
    int a,b,c,x,y,mn = INT_MAX;
    cin >> a >> b >> c >> x >> y;
    for(int i = 0;i <= 100000;i++){
        mn = min(mn,i*2*c+max(0,x-i)*a+max(0,y-i)*b); 
    }
    cout << mn << endl;
    return 0;
}
