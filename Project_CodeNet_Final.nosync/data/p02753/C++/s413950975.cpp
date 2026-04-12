#include <bits/stdc++.h>
#define len(x) (int) (x.size())
using namespace std;
typedef long long ll;

int main() {
    int a = 0, b = 0;
    string s;
    cin >> s;

    for(char c : s) {
        if (c == 'A') a++;
        if (c == 'B') b++;
    }

    if (a != 0 && b != 0) {
        cout << "Yes" << '\n';
    }
    else {
        cout << "No" << '\n';
    }
    
    return 0;
}