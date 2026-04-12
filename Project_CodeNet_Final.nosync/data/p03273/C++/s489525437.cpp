#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int h,w;cin>>h>>w;

	string s[h];
	for(int i=0;i<h;i++)cin>>s[i];

	vector<int> row;
	set<int>col;

	for(int i=0;i<h;i++){
		bool ch = 0;
		for(int j=0;j<w;j++){
			if(s[i][j]=='#'){
				ch=1;
				break;
			}
		}
		if( ch ){row.push_back(i);}
	}

	for(int i=0;i<w;i++){
		bool ch = 0;
		for(int j=0;j<row.size();j++){
			if(s[row[j]][i]=='#'){
				ch=1;
				break;
			}
		}
		if( ch ){col.insert(i);}
	}
	
	string ans[row.size()];

	for(int i=0;i<row.size();i++){

		string t="";

		for(int j=0;j<w;j++){
			if(col.find(j)!=col.end()){
				t+=s[row[i]][j];
			}
		}
		ans[i]=t;
	}

	for(int i=0;i<row.size();i++){

		cout<<ans[i]<<endl;
	}

	

	return 0;

}