#include <bits/stdc++.h>
using namespace std;

int main() {
    int X,Y,Z;
    cin>>X>>Y>>Z;
    int human=0;
    X-=2*Z;
    while(1){
        if(X-Y>=0){
            human+=1;
            X-=Y;
        }else{
            cout<<human<<endl;
            return 0;
        }
        if(X-Z>=0){
            X-=Z;
        }else{
            cout<<human<<endl;
            return 0;
        }
    }
return 0;}
/*
g++ code.cpp
./a.out
*/