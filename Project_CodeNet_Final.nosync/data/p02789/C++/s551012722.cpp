#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int m=0,n=0;
    while(cin>>m){
        cin>>n;
        if(m==n){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}