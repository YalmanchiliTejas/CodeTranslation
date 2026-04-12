#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<string>
#include<vector>
#include<tuple>
#include<stack>
#include<iomanip>
#include<map>
using namespace std;

int main() {
	char a;
	cin >> a ;
	if (a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o') cout << "vowel";
	else cout << "consonant";
	return 0;
}