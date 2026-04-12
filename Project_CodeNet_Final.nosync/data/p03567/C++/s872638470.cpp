#include <iostream>
#include <string>
using namespace std;


int main(){
    string S;
        
    cin >> S;
        
    int a = S.find("AC");
        
    if (a == string::npos){
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
}