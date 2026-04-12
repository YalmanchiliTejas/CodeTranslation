#include <iostream>
#include <string>
using namespace std;
char s[30];
int main(){
    cin>>s[0]>>s[1]>>s[2];
    if(s[1] == s[2] && s[2] == s[0]){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
    return 0;
}