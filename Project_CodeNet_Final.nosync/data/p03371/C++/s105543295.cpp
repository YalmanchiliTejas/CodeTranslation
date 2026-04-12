#include <iostream>
using namespace std;


int main(){
    int64_t a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int64_t mincost = 999999999999999;
    int64_t cost = 0;
    for(int i = 0; i <= max(x, y); i++){
        cost = 2*c*i + a*max(x-i, (int64_t)0) + b*max(y-i, (int64_t)0);
        if(cost < mincost){
            mincost = cost;
        }
    }
    
    cout << mincost << endl;
}