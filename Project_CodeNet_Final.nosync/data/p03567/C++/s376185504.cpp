#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <iostream>
#include <functional>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
	string S;
	cin >> S;
	auto i = S.find("AC");
	if (i != wstring::npos)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
