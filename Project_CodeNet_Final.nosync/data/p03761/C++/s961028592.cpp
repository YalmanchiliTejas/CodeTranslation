// C - 怪文書 / Dubious Document
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	vector<int> a(26, 50);
	for(int i=0; i<n; i++){
		string s; cin>>s;
		vector<int> b(26);
		for(char e:s) b[e-'a']++;
		for(int j=0; j<26; j++) if(a[j]>b[j]) a[j] = b[j];
	}
	for(int i=0; i<26; i++) while(a[i]--) cout<<(char)(i+'a');
	cout<<"\n";
}