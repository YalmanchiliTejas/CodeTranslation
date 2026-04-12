#include <bits/stdc++.h>
#define debug(x) cout << #x << ": " << (x) << endl
using namespace std;

using ull = unsigned long long;
using ll = long long;

using Int = int;
using Double = double;

using P = pair<Int, Int>;
using V = vector<Int>;
using M = vector<V>;

const double PI  = 3.141592653589793238463;
const int MOD = 1000000007;
const Int INF = numeric_limits<Int>::max() / 3;

template<typename T>
istream& operator >> (istream& is, vector<T>& vec){
    for(T& x: vec){
        is >> x;
    }
    return is;
}

template<typename T>
string join(const vector<T>& vec, string sep = " "){
    stringstream ss;
    for(int i = 0; i < vec.size(); i++){
        ss << vec[i] << (i + 1 == vec.size() ? "" : sep);
    }
    return ss.str();
}

/*
 * X >= n(Y + Z) + Z
 * n <= (X - Z) / (Y + Z)
 */
int solve(int x, int y, int z){
    return (x - z) / (y + z);
}

int main(int argc, char* argv[]){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int x, y, z;
    cin >> x >> y >> z;
    cout << solve(x, y, z) << endl;

    return 0;
}
