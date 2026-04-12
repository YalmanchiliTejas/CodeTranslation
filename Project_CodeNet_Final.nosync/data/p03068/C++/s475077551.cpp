#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;
 
int main() {
    int i, i1, i2;
    string s;
    string ans;
    cin >> i1;
    cin >> s;
    cin >> i2;
    for (i=0;i1>i;i++) {
        if (s[i] == s[i2-1]) {
            ans += s[i2-1];
        } else {
            ans += "*";
        }
    }
    cout << ans << endl;
}