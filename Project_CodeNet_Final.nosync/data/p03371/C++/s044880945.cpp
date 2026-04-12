#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
int max(int a,int b){
    return (a > b)?a:b;
}
int min(int a,int b){
    return (a < b)?a:b;
}
int main()
{
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int cost[30];
    cost[0] = C*max(X,Y)*2;
    cost[1] = C*min(X,Y)*2+(max(X,Y)-min(X,Y))*((X>Y)?A:B);
    cost[2] = A*X+B*Y;
    sort(&cost[0],&cost[3]);
    cout << cost[0];
    return 0;
}