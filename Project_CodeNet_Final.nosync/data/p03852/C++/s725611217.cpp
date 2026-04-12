#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
using namespace std;

int N, A;
int x[111];
ll coudp[111][111][5555];

int main() 
{
	char c;
	cin >> c;
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
	{
		cout << "vowel" << endl;
	}
	else
	{
		cout << "consonant" << endl;
	}

	return 0;
	
}