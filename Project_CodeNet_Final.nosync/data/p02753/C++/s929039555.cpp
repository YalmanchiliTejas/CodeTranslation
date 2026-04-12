#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N;
    string s;
    cin >> s;

    bool A = false;
    bool B = false;
    for (char c : s){
        if (c == 'A'){
            A = true;
        }
        else if (c == 'B')
        {
            B = true;
        }
        
    }

    if (A && B){
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
}