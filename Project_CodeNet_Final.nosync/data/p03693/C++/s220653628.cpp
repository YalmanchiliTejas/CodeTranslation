#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
	int a, b, c; cin >> a >> b >> c;

	if ( (a*100 + b*10 + c) % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}
