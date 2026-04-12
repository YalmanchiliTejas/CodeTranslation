#include <iostream>
using namespace std;
int main(void){
    string A;
    cin>>A;
    if (A[0]==A[1] && A[0]==A[2]) {
        cout<<"No"<<endl;
    }
    else {
    cout<<"Yes"<<endl;
    }
    return 0;
}
