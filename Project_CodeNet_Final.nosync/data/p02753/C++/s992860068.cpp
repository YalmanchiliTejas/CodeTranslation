#include <bits/stdc++.h>
using namespace std;

 
int main() {
    string S;
    cin >>S;
    bool T =false;
    if(S.at(1)!=S.at(0)||S.at(1)!=S.at(2)) T=true;
    if(T) cout << "Yes" << endl;
    else cout << "No" << endl;

    }
