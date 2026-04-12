
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

long long counter=0;

void set(long long n,long long x){
    if(n==0){
if(x==0){
return;
}
else{
        counter+=1;
        return;
}
    }
    else if(x==1||x==0){
        return;
    }
    else if(x>=pow(2,n+1)-1){
        counter+=pow(2,n);
        set(n-1,x-pow(2,n+1)+1);
        return;
    }
    else{
        set(n-1,x-1);
        return;
    }
    
        }

int main(){
    long long N;
    long long X;
    cin>>N>>X;
    set(N,X);
    cout<<counter<<endl;
    
    
    
    

}
