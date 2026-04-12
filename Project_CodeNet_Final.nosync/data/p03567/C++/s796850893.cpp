#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <deque>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	string s;
	cin >> s;

	bool flag = false;

	rep(i,s.size()-1)
		if (s.substr(i, 2) == "AC") {
			flag = true;
			break;
		}

	if (flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	
	return 0;
}