#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin>>s;
	int e=s.size();
	int ans=0;
	for(int i=0;i<e-1;i++) {
		if(s[i]=='A'&&s[i+1]=='C') {
			cout<<"Yes"<<endl;
			ans++;
			break;
		}
	}
	if(ans==0) {
		cout<<"No"<<endl;
	}
}
