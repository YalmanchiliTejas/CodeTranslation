#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <algorithm>
#define PB push_back
#define ll long long
#define ull unsigned long long
#define uint unsigned
#define PIE (3.14159265358979323846)
#define MOD 1000000007;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    bool a {false}, b {false};
    for (auto const &val: s) {
        if (val == 'A') a = true;
        else if (val == 'B') b = true;
    }

    if (a && b) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
