#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int n = max(x,y);
    unsigned int min = -1;
    for(int i = 0; i <= n; i++){
        int cost = i*2*c + max(0,x-i) * a + max(0,y-i) * b;
        if(min > cost)
            min = cost;
    }
    cout << min;
}