#include<bits/stdc++.h>

using namespace std;


string str;

bool guide0, guide1;

int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'A')
			guide0 = 1;
		else
			guide1 = 1;
	}
	if (guide0 == guide1)
		cout << "Yes";
	else
		cout << "No";
}
