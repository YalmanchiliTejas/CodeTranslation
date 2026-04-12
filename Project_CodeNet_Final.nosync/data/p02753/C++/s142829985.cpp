#include <iostream>
using namespace std;

#define rep(i, x) for(int i=0;i<(x);i++)

int main(){
    char s[3];
    cin >> s;
    if(s[0] != s[1] || s[0] != s[2] || s[1] != s[2]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}