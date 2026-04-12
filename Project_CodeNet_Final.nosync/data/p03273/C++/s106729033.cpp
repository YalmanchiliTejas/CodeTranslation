#include<bits/stdc++.h>
using namespace std;

int main() {
	int h,w;
	cin>>h>>w;
	char square[h][w];
	
	for(int i=0;i<h;i++)
		scanf("%s",&square[i]);
	
	bool tmp=1;
	for(int i=0;i<h;i++) {
		tmp=1;
		for(int j=0;j<w;j++)
			if(square[i][j]=='#')
				tmp=0;
		if(tmp==1) {
			square[i][0]='1';
			for(int j=1;j<w;j++)
				square[i][j]=='0';
		}
	}
	
	for(int j=0;j<w;j++) {
		tmp=1;
		for(int i=0;i<h;i++)
			if(square[i][j]=='#')
				tmp=0;
		
		if(tmp==1) for(int i=0;i<h;i++) {
			if(square[i][j]!='1')
				square[i][j]='0';
		}	
	}
	
	for(int i=0;i<h;i++) {
		if(square[i][0]=='1') continue;
		for(int j=0;j<w;j++) {
			if(square[i][j]=='0') continue;
			cout<<square[i][j];
		}
		cout<<endl;
	}
	return 0;
}