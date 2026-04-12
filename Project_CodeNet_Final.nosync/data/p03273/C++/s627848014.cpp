/*
ID: wangjun30
TASK:
LANG: C++
*/
#include<iostream>
using namespace std;
bool unusecol[101],unuserow[101];
int main(){
	int n,m;
	cin>>n>>m;
	char ch[n][m];
	for(int i=0;i<n;i++){
		bool b=true;
		for(int j=0;j<m;j++){
			cin>>ch[i][j];
			b=b&&(ch[i][j]=='.');
		}
		if(b)
			unuserow[i]=true;
	}
	for(int i=0;i<m;i++){
		bool b=true;
		for(int j=0;j<n;j++)
			b=b&&(ch[j][i]=='.');
		if(b)
			unusecol[i]=true;
	}
	for(int i=0;i<n;i++){
		bool b=false;
		for(int j=0;j<m;j++)
			if(unuserow[i]+unusecol[j]==0)
				cout<<ch[i][j],b=true;
		if(b)
			cout<<endl;
	}
	return 0;
}