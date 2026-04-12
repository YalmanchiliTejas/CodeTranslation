//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//ifstream cin("x.in"); ofstream cout("x.out");

string s;

int main() {
    cin.sync_with_stdio(false);

    cin >> s;

    bool ok = 0;
    for (int i = 1; i < (int)s.size(); ++ i) {
        if (s[i - 1] == 'A' && s[ i ] == 'C')
            ok = 1;
    }

    cout << (ok == 1 ? "Yes" : "No");
    return 0;
}
