#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int a = 0;
    for (int i = 0; i < 3; i++) {
        if (s[i] == 'A') {
            a++;
        }
    }

    if ((a == 0) || (a == 3)) {
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}
