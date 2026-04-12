#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n, a[26];
	for(int i = 0; i < 26; i++){
		a[i] = 0;
	}
	cin >> n;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		int b[26];
		for(int i = 0; i < 26; i++){
			b[i] = 0;
		}
		for(unsigned int j = 0; j < s.size(); j++){
				b[int(s[j]) - 97] += 1;
			}
		if(i == 0){
			for(int j = 0; j < 26; j++){
				a[j] = b[j];
			}
			continue;
		}
		for(int j = 0; j < 26; j++){
			a[j] = (a[j] < b[j] ? a[j] : b[j]);
		}
	}
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < a[i]; j++){
			cout << char(i + 97) << flush;
		}
	}
	cout << endl;
	return 0;
}