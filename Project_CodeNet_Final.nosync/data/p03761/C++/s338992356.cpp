#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int n, num[26] = {}, now[26] = {};
char s[51];

int main(){
	for (int i = 0; i < 26; i++){
		num[i] = INT_MAX;
	}

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s;

		int a = 0;
		while (s[a] != 0){
			now[s[a] - 'a']++;
			a++;
		}

		for (int i = 0; i < 26; i++){
			num[i] = min(now[i], num[i]);
			now[i] = 0;
		}
	}

	for (char i = 'a'; i <= 'z'; i++){
		for (int j = 1; j <= num[i -'a']; j++){
			cout << i;
		}
	}

	cout << endl;

	return 0;
}