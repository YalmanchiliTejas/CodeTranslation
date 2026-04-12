#include<bits/stdc++.h>
using namespace std;


int main(){
	int n,k;
	char ch;
	string s;
	cin >> n >> s >> k;
	
	ch=s[k-1];
	for(int i=0;i<n;i++){
		if(s[i]!=ch){
			s[i]='*';
		}
	}
	
	for(int i=0;i<n;i++){
		cout << s[i];
	}
	cout << endl;
	return 0;
}