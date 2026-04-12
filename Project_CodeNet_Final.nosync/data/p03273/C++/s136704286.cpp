#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	char s[100][100];
	int h,w;
	bool row[100]={},col[100]={};


	cin>>h>>w;

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>s[i][j];
			if(s[i][j]=='#'){
				 row[i]=true;
				 col[j]=true;
			 }
		}
	}

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(row[i]&&col[j]) cout<<s[i][j];
		}
		if(row[i]) cout<<endl;
	}



	return 0;
}
