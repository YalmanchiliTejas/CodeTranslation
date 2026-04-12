#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

ll comb2(int);

int main()
{
	char c;
	cin >> c;
	if (c=='a'|| c == 'e' || c == 'i' || c == 'o' || c == 'u')
	{
		cout << "vowel";
	}
	else
	{
		cout << "consonant";
	}
	return 0;
}