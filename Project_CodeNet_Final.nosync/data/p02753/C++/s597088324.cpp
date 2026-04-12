#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    char a = s[0];
    bool b = false;
    for(int i = 1; i < 3; i++){
        if(s[i] != a) b = true;
    }
    if(b){
        cout << "Yes";
    } else {
        cout << "No";
    }
}
