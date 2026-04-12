#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    //and it fucked the entire hardwork just bcz it we need to buy 2 for the same
    c=2*c;
    if(a>=c && b>=c){
        cout<<max(x,y)*c;
    }else if(a>=c && b<c){
        if(x>=y){
            cout<<x*c;
        }else{
            cout<<x*c+(y-x)*b;
        }
    }else if(a<c && b>=c){
        if(y>=x)cout<<y*c;
        else cout<<y*c+(x-y)*a;
    }else if(a<c && b<c){
        if(a+b>=c){
            ll allc,sep;
            allc=(x+y)*c;
            ll mn=min(x,y);
            sep=mn*c+(x-mn)*a+(y-mn)*b;
            cout<<min(allc,sep);
        }
        else cout<<x*a+y*b;
    }
}
