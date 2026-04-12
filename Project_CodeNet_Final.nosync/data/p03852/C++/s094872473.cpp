#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	char a;
	cin >> a;
	if (a!='a' && a!='e' && a!='i' && a!='o' && a!='u') cout << "consonant\n";
	else cout << "vowel\n";
}