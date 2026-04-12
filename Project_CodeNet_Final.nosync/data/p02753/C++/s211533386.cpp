#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> P;

int main(){
	string s;
	cin>>s;
	bool ok1=false,ok2=false;
	for(int i=0;i<s.size();i++){
		if(s[i]=='B')ok2=true;
		else ok1=true;
	}
	if(ok1&&ok2)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
