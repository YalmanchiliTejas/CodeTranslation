#include<bits/stdc++.h>

using namespace std;

int main(){
	string str;
  	cin>>str;
  	sort(str.begin(),str.end());
  	if(str[0]=='A' && (str[1]=='B' || str[2]=='B'))
      	cout<<"Yes"<<endl;
  	else
      	cout<<"No"<<endl;
}