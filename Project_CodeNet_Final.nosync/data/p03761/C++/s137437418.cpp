#include<iostream>
#include<string>
using namespace std;

#define ALPHABET 26
int main() {
	int alphabet[ALPHABET], n, count[ALPHABET], num;
	string s;
	for (int i = 0;i < ALPHABET;i ++) alphabet[i] = 0;
	
	
	cin >> n >> s;
	for (int i = 0;i < s.size();i ++) {
		alphabet[s[i]-'a']++;
	}
	for (int i = 1;i < n;i ++) {
		for (int j = 0;j < ALPHABET;j ++)count[j] = 0;
		cin >> s;
		num = 0;
		for (int j = 0;j < s.size();j ++) {
			count[s[j]-'a']++;
		}
		for (int j = 0;j < ALPHABET;j ++) {
			if (alphabet[j] > count[j]) alphabet[j] = count[j];
		}
	}
	for (int i = 0;i < ALPHABET;i ++) {
		for (int j = 0;j < alphabet[i];j ++) {
			cout << (char)('a'+i);
		}
	}
}