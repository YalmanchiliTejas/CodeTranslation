#include<bits/stdc++.h>
using namespace std;
string s[60];
int cnt[60][150],n;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
		for(int j=0;s[i][j];j++)
			cnt[i][s[i][j]]++;
	}
	for(int i=0;i<150;i++){
		int mn=10000000;
		for(int j=0;j<n;j++)
			mn=min(mn,cnt[j][i]);
		for(int j=0;j<mn;j++)
			cout<<char(i);
	}
	return 0;
}