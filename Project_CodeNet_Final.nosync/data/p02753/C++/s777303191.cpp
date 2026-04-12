#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    string s;
    cin >> s ;
    int check =0;
    for(int i=0;i<2;i++){
        if(s[i] != s[i+1]){
            cout << "Yes" << endl;
            check = 1;
            break;
        
        }
    }
    if(check == 0){
        cout << "No" << endl;
    }
}
