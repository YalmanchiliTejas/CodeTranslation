#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int check[51][30];
int main(){
	string s,ans="";
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<s.length();j++){
			check[i][s[j]-'a']++;
		}
	}
	for(int i=0;i<='z'-'a';i++){
		int minimam=check[0][i];
		for(int j=1;j<n;j++)minimam=min(minimam,check[j][i]);
		for(int j=0;j<minimam;j++)ans+='a'+i;
	}
	cout<<ans<<endl;
}
