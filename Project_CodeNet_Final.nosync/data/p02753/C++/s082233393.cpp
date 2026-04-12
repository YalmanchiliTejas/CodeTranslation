#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	
	int cnt_a=0,cnt_b=0;
	
	for(int i=0;i<s.size();i++){
		if(s[i]=='A') cnt_a++;
		else if(s[i]=='B') cnt_b++;
	}
	
	if(cnt_a>=1 && cnt_b>=1)
		cout<<"Yes";
	else
		cout<<"No";
		
	cout<<endl;
	return 0;
} 