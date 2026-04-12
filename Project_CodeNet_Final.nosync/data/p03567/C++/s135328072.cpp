#include <bits/stdc++.h>
using namespace std;
int main (){
	string s;
	cin>>s;
	bool ans = false;
	for(int i=0;i<s.length()-1;i++){
		if(s[i] == 'A' && s[i+1] == 'C') ans = true;
	}
	if(ans) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}