#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

#define PI 3.141592653589793238
#define INF 1050000000

using namespace std;



//cout << fixed << setprecision(15) << << endl;
//cout << << endl;

int main() {

	char c;

	cin >> c;

	if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' )cout << "vowel" << endl;
	else cout << "consonant" << endl;


	return 0;
}