#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    string S;
    cin >> S;
    for (int i = 0; i < (int)S.size()-1; i++) {
        if (S.substr(i, 2) == "AC") {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}