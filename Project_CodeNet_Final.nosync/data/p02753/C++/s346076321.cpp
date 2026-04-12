#include <iostream>
using namespace std;

int main(){
    char A[3];
    int a = 0;
    int b = 0;
    for(int i = 0; i < 3; i++) cin >> A[i];
    for(int i = 0;i < 3; i++){
        if(A[i] == 'A') a= 1;
        if(A[i] == 'B') b = 1;

    }
    //cout << a << b << "\n";
    if(a == 1 && b == 1){
        cout << "Yes";
    } else{
        cout << "No";
    }
    return 0;
    
}