#include<bits/stdc++.h>
using namespace std;

int main () {
    string S;
    cin >> S;
    char a=S.at(0);
    char b=S.at(1);
    char c=S.at(2);

    if (a==b && b==c) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
}
