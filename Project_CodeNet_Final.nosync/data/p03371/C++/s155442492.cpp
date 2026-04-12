#include<iostream>
using namespace std;

int main(){
    int A,B,C,X,Y;
    int price=0,temp=0;
    cin>>A>>B>>C>>X>>Y;
    
    if(A+B>=C*2){
        if(X>Y){
            temp=Y*C*2;
            if(A<2*C)price=(X-Y)*A+temp;
            else price=(X-Y)*C*2+temp;
            }
        else{
            temp=X*C*2;
            if(B<2*C)price=(Y-X)*B+temp;
            else price=(Y-X)*C*2+temp;
            
        } 
    }else{
        price=A*X+B*Y;
    }
    cout<<price<<endl;
}