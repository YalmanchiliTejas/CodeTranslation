//*e**** ********e* *e****e* ****e**
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,k;
	string s;
	cin >> n >> s >> k;

	char c = s[k-1];

	for (string::iterator i = s.begin(); i != s.end(); ++i)
	{
		if(*i != c){
			*i = '*';
		}
	}
	cout << s << endl;
	return 0;
}