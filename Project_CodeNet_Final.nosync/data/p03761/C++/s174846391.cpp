#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int n;

	cin >> n;

	vector<int> alp(26, 1000);


	string s;
	for (int i = 0; i < n; i++){
		cin >> s;
		vector<int> temp(26, 0);

		for (int j = 0; j < s.size(); j++){
			temp[s[j] - 'a']++;
		}

		for (int j = 0; j < 26; j++){
			alp[j] = min(alp[j], temp[j]);
		}
	}



	for (int i = 0; i < 26; i++){
		for (int j = 0; j < alp[i]; j++)
			cout << (char)('a' + i);
	}

	cout << endl;
}