#include <bits/stdc++.h>
using namespace std;

int main(){
    long long A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;

    long long price = X*A + Y*B;
    long long tmp = 0;
    long long tmp2 = max(X,Y)*2;
    for( long long i=1;i<=tmp2;i++){
        if(i<=min(X,Y)){
            tmp = (X-i) *A + (Y-i)*B + C*2*i;
        }
        else if(i<=max(X,Y)){
            if(X<=Y){
                tmp = (Y-i)*B + C*2*i;
            }
            else{
                tmp = (X-i)*A + C*2*i;                
            }
        }
        else{
            tmp = C*2*i;
        }   
        
        // tmp = (X-i) *A;
        // if(tmp<0){
        //     cout<<"A"<< i<<' '<<endl;
        //     break;
        // }
        // tmp = (Y-i)*B;
        // if(tmp<0){
        //     cout<<"B"<< i<<' '<<endl;
        //     break;
        // }
        // tmp = C*2*i;
        // if(tmp<0){
        //     cout<<"C"<< i<<' '<<endl;
        //     break;
        // }
        price = min(price, tmp);
        // cout<<i<<' '<<endl;
        // if(price<0) break;

    }

    cout << price<<endl;


    return 0;
}