#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c, x, y;
    cin>>a>>b>>c>>x>>y;
    
    int cost1, cost2, cost3, cost4, min_cost;
    //A+AB, B+AB, A+B, ABの4通りしかあり得ない
    //A+AB (x>y)
    cost1 = 2*y*c+(x-y)*a;
    //B+AB (x<y)
    cost2 = 2*x*c+(y-x)*b;
    //A+B
    cost3 = x*a+y*b;
    //AB
    cost4 = max(2*x*c, 2*y*c);
    
    if(x<y){
        min_cost=min(min(cost2,cost3),cost4);
    }else{
        min_cost=min(min(cost1,cost3),cost4);
    }
    cout<<min_cost<<endl;
    
    return 0;
}
