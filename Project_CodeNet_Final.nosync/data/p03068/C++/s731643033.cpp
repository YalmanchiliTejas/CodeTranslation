#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string s,t;
	int n, k;
	cin >> n >> s >> k;
	t = s.substr(k - 1, 1);
	for (int i = 0; i < n; ++i) {
		if (s.substr(i, 1) != t) { 
			s.replace(i, 1, "*"); 
		}
	}
	cout << s << "\n";
	return 0;	
}