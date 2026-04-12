#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int answer=A*X+B*Y;
    int upper=max(X,Y);
    for(int i=1;i<=upper;i++){
        int x=X-i,y=Y-i;
        if(X-i<0) x=0;
        if(Y-i<0) y=0;
        int sum=A*x+B*y+C*(2*i);
        answer=min(answer,sum);
    }
    cout << answer << endl;
    return 0;

}