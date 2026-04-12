#include <iostream>
#include <string>

#define max 51

using namespace std;

int min(int a,int b){
	return a < b ? a : b;
}

int main(void){
	int n;
	cin >> n;
	int res[26],box[26];
	for(int i=0;i<26;i++)res[i] = max;
	for(int i=0;i<n;i++){
		int box[26] = {0};
		string s;
		cin >> s;
		for(int i=0;i<s.length();i++){
			box[s[i]-'a']++;
		}
		for(int i=0;i<26;i++){
			res[i] = min(res[i],box[i]);
		}
	}
	for(int i=0;i<26;i++){
		for(int j=0;j<res[i];j++){
			cout << char('a'+i);
		}
	}
	cout << endl;
}