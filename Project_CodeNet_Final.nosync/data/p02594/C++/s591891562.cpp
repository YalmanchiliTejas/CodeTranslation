/**
 * The man who codes no bugs
 * McCheng is the man studying Maths in CUHK with IQ200
 * @author McCheng
 */

#include <bits/stdc++.h>
using namespace std;

class AAirConditioner {
public:
    static constexpr int kStressCount = 0;
    static void generateTest(ostream& test) {}
	void solve(istream& cin, ostream& cout) {
int n;
cin>>n;
if (n>=30){
    cout << "Yes";
} else cout << "No";
	}
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    istream &in(cin);
    ostream &out(cout);
    out << fixed;
    out.precision(20);
    AAirConditioner solver;
    solver.solve(in, out);
}
