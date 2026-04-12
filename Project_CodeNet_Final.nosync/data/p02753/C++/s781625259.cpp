#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <limits>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <cmath>


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;
typedef stringstream ss;
const int mii = numeric_limits<int>::min();
const int mai = numeric_limits<int>::max();
const ll mil = numeric_limits<long long>::min();
const ll mal = numeric_limits<long long>::max();

#define REP(i, a, b) for(long long i=a; i<=b; ++i)
#define RREP(i, a, b) for(long long i=a; i>=b; --i)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)

int main(int argc, char **argv) {
    string s;
    cin >> s;

    set<char> chars;
    for(auto c : s)
        chars.insert(c);

    if(chars.size() > 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}