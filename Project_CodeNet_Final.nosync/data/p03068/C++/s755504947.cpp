#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
int main(){
	int n;
	string s;
	int k;
	cin >>n>>s>>k;
	char a=s[k-1];
	for(auto i = s.begin();i!=s.end();i++){
	if (*i!=a)
		*i='*';
	}
	cout <<s;

}