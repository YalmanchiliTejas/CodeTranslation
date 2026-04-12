#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
typedef long long ll;
 
int main() {
	ios::sync_with_stdio(false);
	int a, b, c;
	cin >> a >> b >> c;
	if ((a * 100 + b * 10 + c) % 4 == 0) cout << "YES\n";
	else cout << "NO\n"; 
}
