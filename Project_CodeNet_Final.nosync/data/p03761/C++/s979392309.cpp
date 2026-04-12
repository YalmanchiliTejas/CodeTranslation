#include <bits/stdc++.h>
using namespace std;

int main () {

	int n,str1[26],str2[26],l;
	string s,ans;

	cin >> n;
	for(int i=0;i<26;i++)str1[i]=50;


	for (int i=0;i<n;i++){
		cin >> s;
		l = s.size();
		for(int j=0;j<26;j++)str2[j]=0;
		for(int j=0;j<l;j++){
			str2[s[j]-'a']++;
		}
		for(int j=0;j<26;j++){
			str1[j] = min(str1[j],str2[j]);
		}
	}

	for(int i=0;i<26;i++){
		for(int j=0;j<str1[i];j++){
			ans.push_back('a'+i);
		}
	}
	cout << ans;

	
    return 0;
}