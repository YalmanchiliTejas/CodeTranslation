#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    string S;
    cin >> S;
    int i;
    for (i = 1; i < 3; i++) {
        if (S[i-1] != S[i]) {
            cout << "Yes";
            break;
        }
    }
    if (i == 3)
        cout << "No";
}