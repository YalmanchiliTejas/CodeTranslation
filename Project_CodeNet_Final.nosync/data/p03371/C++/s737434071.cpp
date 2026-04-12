#include<bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C ,X, Y;
    cin >> A >> B >> C >> X >> Y;
    
    int y1, y2, y3;
    y1 = A*X + B*Y;
    y2 = (X>Y ? 2*Y*C+(X-Y)*A : 2*X*C+(Y-X)*B);
    y3 = (X>Y ? 2*X*C : 2*Y*C);
    
    int min = y1;
    if(min>y2)  min = y2;
    if(min>y3)  min = y3;
    
    cout << min << endl;
    
    
    
    return 0;

}



