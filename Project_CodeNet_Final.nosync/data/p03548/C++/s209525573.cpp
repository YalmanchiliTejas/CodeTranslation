#include<iostream>

using namespace std;

int main(){
    int count,X,Y,Z;
    cin >>X>>Y>>Z;

    count =1+ (X-Y-2*Z)/(Y+Z);

    cout<<count<<endl;
}