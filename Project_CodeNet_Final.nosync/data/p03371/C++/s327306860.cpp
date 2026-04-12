#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    cout<<min({A*X+B*Y,2*C*max(X,Y),min(X,Y)*2*C+abs(X-Y)*(X>Y?A:B)})<<endl;
}