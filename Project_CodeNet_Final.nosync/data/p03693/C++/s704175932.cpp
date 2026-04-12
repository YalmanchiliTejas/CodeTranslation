#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <stdint.h>
#include <math.h>
#include <algorithm>

using namespace std;

class Task {
	public:
		void solve(istream &in, ostream &out) {
            int r, g, b;
            in >> r >> g >> b;
            string n_str = to_string(r) + to_string(g) + to_string(b);
            int n = stoi(n_str);
            
            if (n % 4 == 0) cout << "YES";
            else cout << "NO";            
		}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	istream &in(cin);
	ostream &out(cout);
	Task t;
	t.solve(in, out);
	return 0;
}
