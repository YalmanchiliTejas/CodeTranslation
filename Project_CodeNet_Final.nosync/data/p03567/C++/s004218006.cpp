#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
	string str;
	cin >> str;

	rep(i, str.length() - 1) {
		
		if (str.substr(i, 2) == "AC") {
			cout << "Yes" << endl;
			return 0;
		}
		//cout << str.substr(i,2) << endl;
	}
	cout << "No" << endl;
	
    return 0;
}