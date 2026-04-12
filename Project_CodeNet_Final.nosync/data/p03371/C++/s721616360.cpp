#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int cost1= A*X+B*Y;
    int cost2=0;
    if(X<Y){
        cost2=min(C*X*2+(Y-X)*B,C*Y*2);
    }
    else cost2=min(C*Y*2+(X-Y)*A,C*X*2);
    cout << min(cost1,cost2) << endl;
    }