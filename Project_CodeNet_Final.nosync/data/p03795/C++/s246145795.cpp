#include <iostream>
using namespace std;
int main(){
    int x,y,n;
    cin>>n;
    if(n/15>=1){
        y=(n/15)*200;
    }
    else{
        y=0;
    }
    
    cout<<(800*n)-y<<endl;
}