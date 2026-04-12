#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
int MOD = 1000000007;

int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    
    int a=0,b=0,c=0;
    
    a = A*X+B*Y;
    b = C*2*max(X,Y);
    if(X>Y) c = (C*2*Y)+(X-Y)*A;
    else if(X<Y)  c = (C*2*X)+(Y-X)*B;
    else c = C*2*X;
    
    cout << min({a,b,c}) << endl;
    
    return 0;
}
