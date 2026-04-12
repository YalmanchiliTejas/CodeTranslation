#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    int r, g, b;
    cin >> r >> g >> b;
    int in = r * 100 + g * 10 + b;
    if (in % 4 == 0) {
    	cout << "YES";
	} else {
		cout << "NO";
	}
    return 0;
}
