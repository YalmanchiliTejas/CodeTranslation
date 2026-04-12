#include<iostream>
using namespace std;

int main(){
    int X,Y,Z; cin>>X>>Y>>Z;

    for(int i=0;;i++){
        if(X<=((Y+Z)*i+Z)){
            if(X==((Y+Z)*i+Z)){
                cout<<i<<endl;
                return 0;
            }else{
                cout<<i-1<<endl;
                return 0;
            } 
        }
    }
}