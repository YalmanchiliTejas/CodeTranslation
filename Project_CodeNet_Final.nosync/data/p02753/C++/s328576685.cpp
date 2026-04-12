#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    if(str.at(0) == str.at(1) && str.at(1) == str.at(2)){
        cout << "No" << endl;
        return 0;
    }
    
    cout << "Yes" << endl;
    return 0;
}