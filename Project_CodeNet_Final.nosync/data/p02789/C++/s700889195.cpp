#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

long long n,m;

int main () {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

cin >> n >> m;

if (n==m)
	cout << "Yes";
else
	cout << "No";

return 0;
}

