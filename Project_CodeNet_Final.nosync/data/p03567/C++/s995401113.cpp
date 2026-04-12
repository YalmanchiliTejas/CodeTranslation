#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	string s;
	cin>>s;
	for (int i = 0; i < s.size()-1; ++i)
		{
			if(s[i]=='A' and s[i+1]=='C'){
				cout<<"Yes"<<endl;
				return 0;
			}
		}	
		cout<<"No"<<endl;

	return 0;	
}