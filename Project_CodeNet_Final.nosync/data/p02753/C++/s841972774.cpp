#include <iostream>
using namespace std;

int main(){
    string str;cin >> str;
    char c = str.c_str()[0];
    for (int i = 1; i < 3; i++) {
        if (c != str.c_str()[i]) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}
