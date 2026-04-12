#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> s >> k;

    char a = s[k - 1];
    for (int i = 0; i < s.size(); ++i){
        if (s[i]!= a) {
            s[i] = '*';
        }
    }

    cout << s << endl;
}
