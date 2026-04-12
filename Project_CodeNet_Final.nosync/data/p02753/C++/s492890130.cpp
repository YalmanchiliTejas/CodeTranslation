#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL);
	string s;cin>>s;
	int count1=0; int count2=0;
	for(int i=0;i<3;i++){
		if(s[i]=='A'){
			count1++;
		}
		else{
			count2++;
		}
	}
	if(count1>0 && count2>0){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
}