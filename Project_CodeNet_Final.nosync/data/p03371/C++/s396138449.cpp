#include<bits/stdc++.h>
using namespace std;

int main(){
    int A=0,B=0,C=0,X=0,Y=0,vir=0,ans=1000000000;
    cin >> A >> B >> C >> X >> Y ;
    for(int i=0;i<=200000;i+=2){
        vir=C*i;
        if(X>i/2)vir+=A*(X-i/2);
        if(Y>i/2)vir+=B*(Y-i/2);
        if(ans>vir)ans=vir;
    }
    cout << ans << endl;
    return 0;
}