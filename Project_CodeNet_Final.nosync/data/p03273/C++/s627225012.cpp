#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int h,w;cin>>h>>w;

	string s[h];
	for(int i=0;i<h;i++)cin>>s[i];

	vector<int> row(h,false),col(w,false);

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(s[i][j]=='#'){
				row[i]=true;
				col[j]=true;
			}
		}
	}

	for(int i=0;i<h;i++)
		if(row[i]){
			for(int j=0;j<w;j++)
				if(col[j]) cout<<s[i][j];
			cout<<endl;
		}
	return 0;

}