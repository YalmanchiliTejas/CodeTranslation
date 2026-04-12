#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    bool found = false;
    for(int i = 0; i < 4; i++){
        if(s[i] == 'A' && s[i+1] == 'C')    found = true;
    }

    if(found)   cout << "Yes" << endl;
    else        cout << "No" << endl;
    
    return 0;
}