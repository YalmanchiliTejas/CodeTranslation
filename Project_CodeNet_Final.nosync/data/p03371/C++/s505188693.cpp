#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    int co,div;

    if(X>=Y){
        if((A+B)>=2*C){
            co = 2*C*Y;
            div = X - Y;
            if(2*C>=A){
                co += div*A;
            }else{
                co += div*2*C;
            }
        }else{
            co = (A+B)*Y;
            div = X - Y;
            if(2*C>=A){
                co += div*A;
            }else{
                co += div*2*C;
            }

        }
    }else{
        if((A+B)>=2*C){
            co = 2*C*X;
            div = Y - X;
            if(2*C>=B){
                co += div*B;
            }else{
                co += div*2*C;
            }
        }else{
            co = (A+B)*X;
            div = Y - X;
            if(2*C>=B){
                co += div*B;
            }else{
                co += div*2*C;
            }

        }
    }

    cout<<co<<endl;

    return 0;
}

