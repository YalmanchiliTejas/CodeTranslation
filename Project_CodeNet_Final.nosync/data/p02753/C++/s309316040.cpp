#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    bool a = false;
    bool b = false;
    for(int i = 0;i < 3;i++){
        if(s[i] == 'A')
            a = true;
        if(s[i] == 'B')
            b = true;
    }
    if(a && b){
        cout << "Yes" << endl;
    }else{
        cout << "No" <<endl;
    }
}