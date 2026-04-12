#include<bits/stdc++.h>
using namespace std;
int A,B,C,X,Y;
int min(){
    if(X>Y)return Y;
    else return X;
}
int max(){
    if(X>Y)return X;
    else return Y;
}
int price(){
    if(max()==X)return A;
    else return B;
}


int main(){
    cin>>A>>B>>C>>X>>Y;
    int sum=0;
    if(A+B>=2*C){
        sum+=2*C*min();
        if((max()-min())*price()>=2*C*(max()-min())) sum+=2*C*(max()-min());
        else sum+=(max()-min())*price();
    }
    else{
        sum+=(A+B)*min();
        if((max()-min())*price()>=2*C*(max()-min())) sum+=2*C*(max()-min());
        else sum+=(max()-min())*price();

    }
    cout<<sum;
}