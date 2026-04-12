#include <iostream>
using namespace std;

int main(){
    int X,ok[3]={3,5,7},i;
    cin >> X;
    for(i=0;i<3;i++){
        if(X==ok[i]){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}