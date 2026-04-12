#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int n,i,j,k;
	cin >> n;
	char c;
	vector<int> a(26),b(26);
	for(i=0; i<26; i++){
		b[i]=50;
	}
	for(i=0; i<n; i++){
		cin >> s;
		for(j=0; j<s.size(); j++){
			k=s[j]-'a';
			a[k]++;
		}
		for(j=0; j<26; j++){
			b[j]=min(a[j],b[j]);
			a[j]=0;
		}
	}
	for(i=0; i<26; i++){
		c='a'+i;
		for(j=0; j<b[i]; j++){
			cout << c;
		}
	}
	
}