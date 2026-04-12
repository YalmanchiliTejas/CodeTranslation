#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    if (S.find("AC") <= S.size() - 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
