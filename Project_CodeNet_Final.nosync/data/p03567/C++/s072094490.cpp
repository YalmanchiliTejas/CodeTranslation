#include<iostream>
using namespace std;
#define SZ(a) ((int)(a).size())
int main()
{
	string s;
	cin >> s;
	for (int i = 0; i + 1 < SZ(s); ++i)
		if (s[i] == 'A' && s[i+1] == 'C') {
			cout << "Yes\n";
			return 0;
		} 
	cout << "No\n";
}
