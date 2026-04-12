#include <iostream>
#include <string>
using namespace std;

int main(void){
    string s;
    cin >> s;
    if (s.substr(0,1) == s.substr(1,1) && s.substr(0,1) == s.substr(2,1)){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}