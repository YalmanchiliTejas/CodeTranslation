#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,n,m;
    cin>>a>>b>>c>>n>>m;
    if(a+b<2*c){
        cout<<a*n+b*m;
    }
    else{
        long kq;
        if(m>=n){
            kq=min(m*2*c,n*2*c+(m-n)*b);
            cout<<kq;
        }
        else{
            kq=min(n*2*c,m*2*c+(n-m)*a);
            cout<<kq;
        }
    }
}