#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
typedef long long ll;
using namespace std;

int main()
{
	string s; cin >> s;
	int i;
	if (s[0] == s[1] && s[1] == s[2]) cout << "No";
	else cout << "Yes";
}