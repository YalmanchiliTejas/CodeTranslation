#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;

int main() {
    string  s;
    cin >> s ;
    
    int flag = 0;
    for (int i = 0; i < 2; i++) {
        if (s[i] != s[i + 1])
            flag = 1;
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
}
