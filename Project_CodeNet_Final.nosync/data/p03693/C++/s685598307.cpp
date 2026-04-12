#include <algorithm>
#include <iomanip>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#define ll long long

using namespace std;

class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
        ll r, g, b;
        in >> r >> g >> b;
        ll ans = 100 * r + 10 * g + b;
        out << (ans % 4 == 0 ? "YES" : "NO") << endl;
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}


#include <fstream>
#include <iostream>


int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    istream& in = cin;


    ostream& out = cout;

    solve(in, out);
    return 0;
}


