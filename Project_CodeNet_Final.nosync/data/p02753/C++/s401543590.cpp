#include <iostream>
using namespace std;

int main(){
    char a[3]={};
    for(int i=0;i<3;i++){
        cin >> a[i];
    }
    bool isYes=false;
    char p=a[0];
    for(int i=1;i<3;i++ ){
        if(p!=a[i]){
            cout <<"Yes"<<endl;
            return 0;
        }
    }
    cout << "No" <<endl;
    return 0;
}