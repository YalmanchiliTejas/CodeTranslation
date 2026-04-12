#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;

    cin >> s;

    string Ans = "Yes";

    if(s.at(0) == s.at(1) && s.at(1) == s.at(2)) Ans = "No";

    cout << Ans << endl;

} 
