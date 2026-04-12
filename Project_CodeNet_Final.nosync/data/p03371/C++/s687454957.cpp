#include<bits/stdc++.h>
using namespace std;

int main(){
    int X,Y,A,B,C;
    cin >> A >> B >> C >> X >> Y;
    int ans = A*X+B*Y;
    for(int i=0;max(X,Y)*2>=i;i+=2){
        int x,y;
        x=max(0,X-i/2);
        y=max(0,Y-i/2);
        ans=min(ans,A*x+B*y+C*i);
    }
    cout << ans << endl;
}