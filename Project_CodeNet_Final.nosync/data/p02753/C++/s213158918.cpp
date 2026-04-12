#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,cnt=0,cnt1=0;
	string s;
	cin>>s;
	for(i=0;i<3;i++){
		if(s[i]=='A'){
			cnt++;
		}
		else{
			cnt1++;
		}
	}
	if(cnt>=1&&cnt1>=1){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	return 0;
}