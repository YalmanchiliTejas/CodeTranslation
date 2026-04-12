#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(){
	int n;
	string s;
	int t[26] = {};
	
	for(int i = 0;i < 26;i++)t[i] = 9999999;
	
	cin >> n;

	for(int j = 0;j < n;j++){
		cin >> s;
		int num[26] = {};

		for(int i = 0;i < s.size();i++)num[s[i]-'a'] ++;

		for(int i = 0;i < 26;i++)t[i] = min(t[i],num[i]);
	}

	for(int j = 0;j < 26;j++){
		for(int i = 0;i < t[j];i++)cout << (char)('a'+j);
	}
	cout <<endl;
	return 0;
}