#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	string s[50];
	int c[50][26]={};
	for(int i=0;i<n;i++){
		cin >> s[i];
		for(int j=0;j<s[i].length();j++){
			c[i][s[i][j]-'a']++;
		}
	}
	int cc[26];
	for(int i=0;i<26;i++) cc[i]=50;
	for(int i=0;i<26;i++){
		for(int j=0;j<n;j++){
			if(cc[i]>c[j][i]) cc[i]=c[j][i];
		}
	}
	for(int i=0;i<26;i++){
		if(cc[i]>0)
			for(int j=0;j<cc[i];j++)
				cout << (char)(i+'a');
	}
	cout << endl;
}
