#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

int main(){
	int a, b;
	stringstream ss;
	cin >> a >> b;

	if(a > b) ss << " > ";
	else if(a < b) ss << " < ";
	else ss << " == ";

	cout << 'a' << ss.str() << 'b' << endl;

	return 0;
}