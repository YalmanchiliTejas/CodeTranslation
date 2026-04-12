#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

int main(void){
    string s;
    cin >> s;
    bool flag = s[0] == s[1] && s[1] == s[2];
    if (flag) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}
