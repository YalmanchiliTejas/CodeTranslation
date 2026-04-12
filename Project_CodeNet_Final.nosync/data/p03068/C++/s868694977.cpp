#include <bits/stdc++.h>
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
using namespace std;
int main(){
	int n;
	string s;
	int k;
	cin>>n>>s>>k;
	for(int i=0;i<n;i++){
		if(s[i]!=s[k-1]){
			cout<<"*";
		}else{
			cout<<s[i];
		}
	}
	cout<<endl;
	return 0;
}
