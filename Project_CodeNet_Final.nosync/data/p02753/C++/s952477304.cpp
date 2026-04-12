#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < 3; i++){
        if(s[i] == 'A') a++;
        if(s[i] == 'B') b++;
    }
    if(a >= 1 && b >= 1) s = "Yes";
    else s = "No";
    
    cout << s << endl;
    return 0;
}