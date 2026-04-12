#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int D;
    

    int d[300000];
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    for(int i=0;i<n-1;i++){
        D=max(D,d[i]);

        if(D<10){
            cout<<"no"<<endl;
            return 0;
        }
        D-=10;
    }
    D=0;

    for(int i=n-1;i>0;i--){
        D=max(D,d[i]);

        if(D<10){
            cout<<"no"<<endl;
            return 0;
        }
        D-=10;
    }
    cout<<"yes"<<endl;
    return 0;
}
