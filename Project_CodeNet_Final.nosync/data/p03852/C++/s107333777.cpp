#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <set>
#include <map>
#include <list>
#define debug(x) cout << #x << ": " << (x) << endl
using namespace std;

const double PI  = 3.141592653589793238463;
const int INF = 1000000007;

using ull = unsigned long long;
using ll = long long;

using Int = int;
using Double = double;

using P = pair<Int, Int>;
using V = vector<Int>;
using M = vector<V>;

string solve(char c){
    switch(c){
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return "vowel";
    default:
        return "consonant";
    }
}

int main(int argc, char* argv[]){
    cin.tie(0);
    ios::sync_with_stdio(false);

    char c;
    cin >> c;

    cout << solve(c) << endl;

    return 0;
}
