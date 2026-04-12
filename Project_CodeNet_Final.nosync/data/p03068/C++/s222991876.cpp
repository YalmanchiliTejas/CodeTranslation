#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[k - 1]) {
            s[i] = '*';
        }
    }
    cout << s << endl;
}
