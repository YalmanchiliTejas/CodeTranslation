#include <iostream>
using namespace std;
int x[101];
int main(void){
    for(int i=0;i<12;i++){
        int num;
        cin>>num;
        x[num]++;
    }
    for(int i=1;i<=100;i++){
        if(x[i]%4){
            cout<<"no"<<endl;
            return 0;
        }
    }
    cout<<"yes"<<endl;
    return 0;
}