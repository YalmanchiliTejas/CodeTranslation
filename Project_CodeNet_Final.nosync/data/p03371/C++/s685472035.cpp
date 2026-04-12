#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;
 
int main(){
    
    int A,B,C,X,Y,x,y,ans,tmp;

    cin >> A>>B>>C>>X>>Y;

    x=X%2;
    y=y%2;

    if((A+B)>C*2){
        //Cがお得
        ans = min(X,Y)*C*2;

        if(X>Y){
            ans+=min((X-Y)*A,(X-Y)*2*C);
        }else if(Y>X){
            ans+=min((Y-X)*B,(Y-X)*2*C);
        }

    }else{

        ans=X*A+B*Y;

    }

    cout << ans <<endl;

    return 0;
}