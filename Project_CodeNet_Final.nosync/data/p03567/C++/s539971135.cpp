#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main(void) {

	int a = 0, c = 0;

	string s;

	cin >> s;

	for (int k = 0; k < s.size(); k++) {
		if (s.at(k) == 'A') {
			a++;
		}
		else if (a==1&&s.at(k) == 'C')c++;
		else a = 0;

//		printf("a=%d,c=%d\n", a, c);
	}

	if (c >= 1)cout << "Yes\n";
	else cout << "No\n";


	return 0;
}