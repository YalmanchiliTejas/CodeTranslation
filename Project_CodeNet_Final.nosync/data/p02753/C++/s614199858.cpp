#include <bits/stdc++.h>
//#define int long long
using namespace std;

int main() {
    string s;
    int a = 0, b = 0;
    cin >> s;
    for(int i = 0; i < 3; i++){
        if(s[i] == 'A')
            a++;
        else
            b++;
    }
    if(a == 0 || b == 0)
        cout << "No";
    else
        cout << "Yes";
    
    return 0;
}