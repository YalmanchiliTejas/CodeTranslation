#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    int sum=0;
    while (X>0&&Y>0){
        if(A+B>=2*C){
            sum=sum+C+C;
            X--;
            Y--;
        }
        else{sum=sum+A+B;
            X--;
            Y--;
        }
    }
    while(X!=0){
        if(A>=2*C){
            sum=sum+C+C;
            X--;
        }
        else{sum=sum+A;
            X--;
        }
    }
    while(Y!=0){
        if(B>=2*C){
            sum=sum+C+C;
            Y--;
        }
        else{sum=sum+B;
            Y--;
        }
    }
    cout<<sum<<endl;
}
