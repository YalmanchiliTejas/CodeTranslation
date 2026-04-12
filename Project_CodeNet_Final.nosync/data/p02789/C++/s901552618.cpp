/**
 * @author khokharnikunj8
 */

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

class AACOrWA {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n, m;
        in >> n >> m;
        out << (n == m ? "Yes" : "No") << "\n";
    }
};


int main() {
    AACOrWA solver;
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}
