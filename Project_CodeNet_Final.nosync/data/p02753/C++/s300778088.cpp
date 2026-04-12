#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int cnt=0,cnt1=0;
	string s;
	cin>>s;
	
	for(ll i=0;i<3;i++){
		
		if(s[i]=='A' ||s[i]=='a' ){
			cnt++;
		}else if(s[i]=='B'||s[i]=='b'){
			cnt1++;
		}
	}
	if(cnt>0 && cnt1>0){
		cout<<"Yes"<<endl;
	}else{
	cout<<"No"<<endl;
	}
	return 0;
}
