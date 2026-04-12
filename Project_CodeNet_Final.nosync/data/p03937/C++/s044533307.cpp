#include<iostream>
using namespace std;
main(){
	int h,w;cin>>h>>w;
	string s[10];
	for(int i=0;i<h;i++)cin>>s[i];
	bool flag=false;
	for(int i=1;i<h;i++)for(int j=1;j<w;j++)if(s[i][j-1]!='.'&&s[i-1][j]!='.')flag=true;
	cout<<(flag?"Impossible":"Possible")<<endl;
}