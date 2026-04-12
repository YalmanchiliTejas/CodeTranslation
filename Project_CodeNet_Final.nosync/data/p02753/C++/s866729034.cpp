#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <algorithm> 
#include <set>
#include <sstream>
#include <bit>
#include <bitset>
#include <iomanip>
#include <queue>
typedef long long int ll;
using namespace std;
int main() {
	string S; cin >> S;
	if (S[0] == S[1] && S[1] == S[2]) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
}