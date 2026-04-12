#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <set>
#include <map>
#include <list>
#include <bitset>
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

V count_chars(string& s){
    V res('z' - 'a' + 1);
    for(int i = 0; i < s.size(); i++){
        res[s[i] - 'a']++;
    }
    return res;
}

V count_chars(int n, vector<string>& ss){
    M css;
    for(int i = 0; i < n; i++){
        css.push_back(count_chars(ss[i]));
    }
    V res;
    for(int i = 0; i < 'z' - 'a' + 1; i++){
        int c = 100;
        for(int j = 0; j < n; j++){
            c = min(css[j][i], c);
        }
        res.push_back(c);
    }
    return res;
}


string solve(int n, vector<string>& ss){
    const V& cs = count_chars(n, ss);
    string res;
    for(int i = 0; i < cs.size(); i++){
        res += string(cs[i], 'a' + i);
    }
    return res;
}


int main(int argc, char* argv[]){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> ss(n);
    for(int i = 0; i < n; i++){
        cin >> ss[i];
    }
    cout << solve(n, ss) << "\n";

    return 0;
}
