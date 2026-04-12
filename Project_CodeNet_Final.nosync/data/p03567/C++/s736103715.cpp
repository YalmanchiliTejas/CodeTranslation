#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main(void){
    char a[5];
    int b=0;
    cin>>a;
    for(int i=0;i<5;i++){
        if(a[i]=='A' && a[i+1]=='C'){
            b++;
        }
    }
    if(b==0){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
}