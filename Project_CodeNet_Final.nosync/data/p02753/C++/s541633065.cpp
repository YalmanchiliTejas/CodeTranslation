#include<bits/stdc++.h>
using namespace std;

int main() {
    int n_a = 0, n_b = 0;
    for(int i = 0; i < 3; i++) {
        char c;
        cin >> c;
        if(c == 'A') {
            n_a++;
        }
        else {
            n_b++;
        }
    }    
    if(n_a == 0 || n_b == 0) {
        cout << "No\n";
    }
    else {
        cout << "Yes\n";
    }
    return 0;
}