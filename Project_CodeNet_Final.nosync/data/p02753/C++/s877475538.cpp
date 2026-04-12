#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <memory>

//#define int long long

using namespace std;

void Main()
{
	string s;
	cin >> s;

	int anum = 0;
	int bnum = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'A') anum++;
		if (s[i] == 'B') bnum++;
	}
	
	if (anum == 3 || bnum == 3) {
		cout << "No" << endl;
		return;
	}

	cout << "Yes" << endl;
}

int32_t main()
{
	Main();
	return 0;
}

