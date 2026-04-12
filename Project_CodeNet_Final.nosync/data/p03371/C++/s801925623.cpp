#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    if(a+b<=2*c){
        cout<<a*x+b*y;
        return 0;
    }
    if(x<y){
        if(b<(2*c)){
            cout<<b*(y-x)+c*2*x;
            return 0;
        }else{
            cout<<c*2*y;
            return 0;
        }
    }else{
        if(a<(2*c)){
            cout<<a*(x-y)+c*2*y;
            return 0;
        }else{
            cout<<c*2*x;
            return 0;
        }
    }

}