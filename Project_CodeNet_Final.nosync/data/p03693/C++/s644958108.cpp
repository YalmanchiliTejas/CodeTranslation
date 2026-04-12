#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;

int main(){
    int a, b, c;
    cin>>a>>b>>c;
    int kazu=a*100+b*10+c;
    if(kazu%4==0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
