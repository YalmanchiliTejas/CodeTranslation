#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[27];
	for(int i=1;i<=26;i++){
		a[i]=99999;
	}
	for(int i=1;i<=n;i++){
		string s;
		int b[27]={0};
		cin>>s;
		for(int i=0;i<s.size();i++){
			b[(s[i]-'a')+1]++;
		}
		for(int i=1;i<=26;i++){
			a[i]=min(a[i],b[i]);
		}
	}
	for(int i=1;i<=26;i++){
		for(int j=1;j<=a[i];j++){
			cout<<char(i+'a'-1);
		}
	}
	return 0;
}