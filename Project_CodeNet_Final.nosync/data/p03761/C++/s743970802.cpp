#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	int alf[30] = { };
	for(int i = 0; i < 26; i++) alf[i] = 110000000;
	
	for(int i = 0; i < n; i++) {
		string S;
		cin >> S;
		int tmp[30] = { };
		for(int j = 0; j < S.size();j ++) tmp[S[j] - 'a']++;
		for(int j = 0; j < 26; j++) alf[j] = min(alf[j], tmp[j]);
	}
	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < alf[i]; j++) printf("%c", 'a'+i);
	}
	cout << endl;

	return 0;
}
