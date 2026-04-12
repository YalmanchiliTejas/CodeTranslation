#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using P = pair<int, int>;

int main() {
    string s;

    cin >> s;

    bool flag = true;

    if( s.at(0) == 'A' && s.at(1) == 'A' && s.at(2) == 'A') flag = false;
    if( s.at(0) == 'B' && s.at(1) == 'B' && s.at(2) == 'B') flag = false;


    if(flag) cout << "Yes" << endl;
    else     cout << "No"  << endl;

}