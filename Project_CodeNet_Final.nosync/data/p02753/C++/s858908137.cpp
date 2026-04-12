#include <bits/stdc++.h>
using  namespace std;
int main(){
    string s;
    cin >> s;
    int a = 0;
    int b = 0;
    for(auto c: s){
        if(c == 'A') a ++;
        else b ++;
    }
    if(a && b) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}