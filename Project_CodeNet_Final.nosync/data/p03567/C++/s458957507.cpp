#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    for(int i = 0; i < (int)s.length() - 1; ++i){
        if(s.substr(i, 2) == "AC"){
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}