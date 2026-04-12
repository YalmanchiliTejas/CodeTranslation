#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	string s;
	cin>>s;
	int sum=0;
	int ans=0;
	for(int i=0;i<3;i++){
		if(s[i]=='A')sum++;
		if(s[i]=='B')ans++;
	} 
	if(sum==3||ans==3){
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;
	}
	return 0;
}