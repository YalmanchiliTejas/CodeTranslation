#include<iostream>
#include<algorithm>
#include<vector>
 using namespace std;
 typedef long long ll;
 int main()
 {
 	string s;
 	cin>>s;
 	int x=0,y=0;
 	for(int i=0;i<s.size();i++){
 		if(s[i]=='A') x++;
 		else y++;
	 }
	if(x>0&&y>0) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	 return 0;
  } 