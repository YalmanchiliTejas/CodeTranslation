#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    string S; cin >> S;
    for (int i = 0; i < S.size()-1; i++) {
        if (S[i] == 'A' && S[i+1] == 'C') {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}
