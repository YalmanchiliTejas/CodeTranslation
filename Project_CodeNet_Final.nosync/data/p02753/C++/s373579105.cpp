#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin >> s;
    bool a = false;
    bool b = false;
    for(string::iterator itr = s.begin(); itr != s.end(); itr++){
        if(*itr == 'A') a = true;
        if(*itr == 'B') b = true;
    }
    if(a && b){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}