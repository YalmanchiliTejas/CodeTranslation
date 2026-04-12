#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    bool ac = false;
    for(int i=0; i<s.size()-1; ++i) {
         if(s[i] == 'A' && s[i+1] == 'C') {
             ac = true;
             break;
         }
    }
    if(ac) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}