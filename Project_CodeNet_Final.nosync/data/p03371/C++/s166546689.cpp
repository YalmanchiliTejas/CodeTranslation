#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,x,y,i,tmp=0,ans=0;
    cin >> a >> b >> c >> x >> y;
    for(i=0;i<=max(x,y);i++){
        tmp = 2*c*i + a*max(x-i,0) + b*max(y-i,0);
        if(i==0){ans=tmp;}
        else {if(ans>tmp)ans=tmp;}
        tmp=0;
    }
    cout << ans << endl;
    return 0;
}