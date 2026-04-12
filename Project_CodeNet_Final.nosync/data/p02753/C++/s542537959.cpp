#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <climits>
#include <cmath>
#include <utility>
#include <iomanip>

using namespace std;



int main(int argc, char *argv[])
{
	string s;

	//input
	cin >> s;


	//calc
	string ans;
	if (s == "AAA" || s == "BBB"){
		ans = "No";
	}
	else{
		ans = "Yes";
	}

	//ans
	cout << ans << endl;

	return 0;
}
