#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    vector<char> S(3);
    cin >> S.at(0) >> S.at(1) >> S.at(2);
    if(S.at(0) == S.at(1) && S.at(0) == S.at(2)){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}
