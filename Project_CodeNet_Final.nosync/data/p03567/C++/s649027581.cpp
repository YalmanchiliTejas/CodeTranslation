#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    for(int i = 0; i < s.size() - 1; i++){
        if(s.at(i) == 'A' && s.at(i + 1) == 'C'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}