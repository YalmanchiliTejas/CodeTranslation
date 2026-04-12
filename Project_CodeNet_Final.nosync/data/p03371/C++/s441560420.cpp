#include<iostream>
#include<cmath>
#include<vector>
#include<utility>
#include<string>
using namespace std;

int main(){
    int A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    int totalcost = 0;
    int Z;

    if(X>Y){
        Z = Y;
    }else{
        Z = X;
    }
    X -= Z; Y -= Z;

    int single_cost = (A+B);
    if(2 * C > single_cost){
        totalcost += single_cost * Z;
    }else{
        totalcost += C * 2 * Z;
    }
    //cout<<"totalcost = "<<totalcost<<endl;

    if(X > 0){
        if(A  > C * 2 ){
            totalcost += C * 2 * X;
        }else{
            totalcost += A * X;
        }
    }else if(Y > 0){
        if(B > C * 2 ){
            totalcost += C * 2 * Y;
        }else{
            totalcost += B * Y;
        }
    }

    cout<<totalcost<<endl;

    return 0;
}