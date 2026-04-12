#include <bits/stdc++.h>

using namespace std;
int main(){
    int r,g,b,x,y;
    cin>>r>>g>>b;
    x=100*r+10*g+b;
    y=x%4;
    if (y==0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }



    return 0;
}
