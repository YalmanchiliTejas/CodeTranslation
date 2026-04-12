#include <iostream>
#include <string>

using namespace std;

int n;
string s;
int k;

int main(void)
{
	cin >> n >> s >> k;
	k--;
	for(int i = 0; i < s.size(); i++){
		if(s[i] != s[k]) s[i] = '*';
	}
	cout << s << endl;
	return 0;
}