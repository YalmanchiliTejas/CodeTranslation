#include <bits/stdc++.h>
using namespace std;

int main() {
    string c;

    cin >> c;

    for(int i=0;i<c.size()-1;i++){
        if(c[i] == 'A' && c[i+1] == 'C'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}