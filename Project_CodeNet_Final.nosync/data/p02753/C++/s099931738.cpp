#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    bool a = false;
    bool b = false;
    for(int i=0;i<3;i++) {
        if (S.at(i)=='A') a = true;
        else b = true;
    }
    if (a & b) cout << "Yes" << endl;
    else cout << "No" << endl;

}