#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int cntA=0,cntB=0;
	for (int i=0;i<3;i++){
		if (s[i]=='A') cntA++;
		else cntB++;
	}
	if (cntB&&cntA) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}