#include <bits/stdc++.h>
using namespace std;
int main(void){

    string s;
    cin >> s;
    
    int count = 0;
    for(int i=1; i<3; i++) {
        if(s.substr(i,1) == s.substr(0,1)) {
            count++;
        }
    }

    if(count == 2) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }

    return 0;
}
