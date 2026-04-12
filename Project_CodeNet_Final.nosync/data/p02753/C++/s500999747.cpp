#include <bits/stdc++.h>          
using namespace std;               

int main() {
    string S;
    cin >> S;
    string ans = "Yes";
    if (S=="AAA" or S=="BBB") {
        ans = "No";
    }
    cout << ans << endl;
}