#include<bits/stdc++.h>
using namespace std;

int s1[26], s2[26];

int main(){
	int n;
	string str;
	cin >> n >> str;
	for(int i = 0;i<str.size();i++)
		s1[str[i]-'a']++;
		
	for(int i = 0;i<n-1;i++){
		cin >> str;
		for(int j = 0;j<str.size();j++){
			int d = str[j]-'a';
			s2[d]++;
		}
		
		for(int j= 0;j<26;j++){
			s1[j] = min(s1[j],s2[j]);
		}
		memset(s2,0,sizeof(s2));
	}
	for(int i = 0;i<26;i++){
		for(int j = 0;j<s1[i];j++){
			cout<<(char)('a'+i);
			
		}
	}
}