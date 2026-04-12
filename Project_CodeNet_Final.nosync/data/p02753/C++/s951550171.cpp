#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <tuple>
#include <map>
#include <ctime>
#include <cstdlib>
#include <random>
using namespace std;

int main(){
	string s;
	cin >> s;
	if(s.at(0) == s.at(1) && s.at(1) == s.at(2))cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}