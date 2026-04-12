#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;

    int ca = 0;
    int cb = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'A') ca++;
        if(s[i] == 'B') cb++;

    }

    if(ca == s.length() || cb==s.length()) cout << "No" << endl;
    else cout << "Yes" << endl;


    return 0;
}