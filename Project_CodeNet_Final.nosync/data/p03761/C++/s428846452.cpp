#include<bits/stdc++.h>
using namespace std;
map<char,int> mp[10010];
int main(){
	int n,i,j;
	cin>>n;
	getchar();
	for(i=1;i<=n;i++){
		string s;
		getline(cin,s);
		for(j=0;j<s.size();j++){
			mp[i][s[j]]++;
		}
	}
	string ans;
	for(char k='a';k<='z';k++){
		int t=0x3f3f3f;
		for(i=1;i<=n;i++){
			t=min(t,mp[i][k]);
		}
		if(t>0){
			for(j=1;j<=t;j++){
				ans+=k;
			}
		}
	}
	cout<<ans;
	return 0;
}