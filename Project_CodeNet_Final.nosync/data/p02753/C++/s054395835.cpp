
#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
using namespace std;
typedef long long ll;

const ll MOD_CONST = 1000000007;



int main(){
	string s;
	cin >> s;
	char c = s[0];
	for (int i = 1; i < 3; i++) {
		if (s[i] != c) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;
	return 0;
}  

