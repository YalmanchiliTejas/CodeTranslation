#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    
    c *= 2;
    int min = a * x + b * y;
    
    int cost;
    int i;
    for(i = 1; i <= max({x, y}); i++){
        cost = c * i;
        if(x > i){
            cost += a * (x - i);
        }
        if(y > i){
            cost += b * (y - i);
        }
        if(cost < min){
            min = cost;
        }
    }
    
    cout << min << endl;
    
    return 0;
}
