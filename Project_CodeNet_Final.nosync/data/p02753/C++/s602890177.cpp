#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;
    int flag = 0;
    if(S[0] != S[1]) {
        flag = 1;
    } else {
        if(S[1] != S[2]) {
            flag = 1;
        }
    }
    // cout << S << endl;
    if(flag == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;

}
