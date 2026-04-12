#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;


int main(){
	string s;
	cin >> s;
	if (s[0] == s[1] && s[1] == s[2]) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}
