#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

using namespace std;

typedef long long int lli;

int main() {
    string str;
    cin >> str;
    cout << (str.find("AC") != string::npos ? "Yes" : "No") << endl;
    return 0;
}