#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
	string c; cin >> c;
	if (c[0] == 'a' || c[0] == 'i' || c[0] == 'u' || c[0] == 'e' || c[0] == 'o' ) cout << "vowel" << endl;
	else cout << "consonant" << endl;
}
