#include <algorithm>
#include <array>
#include <climits> // INT_MAX, LONG_MAX, LLONG_MAX, UINT_MAX, ULONG_MAX, ULLONG_MAX
#include <cmath>
#include <cstdint>
#include <cstring> // memset
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#define ALL(x) (x).begin(), (x).end()
#define INF 1e9
#define LOG(x) cout << #x << " = " << (x) << endl
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    string c;
    cin >> c;

    vector<string> v = {"a", "e", "i", "o", "u"};
    cout << (find(v.begin(), v.end(), c) == v.end() ? "consonant" : "vowel") << endl;
    
    return 0;
}
