#include <bits/stdc++.h>
using namespace std;

int main() {
	int r,c;cin>>r>>c;
	vector<string>v(r);vector<bool>row(r,true);vector<bool>col(c,true);
	for(int i=0;i<r;i++)cin>>v[i];
	for(int i=0;i<r;i++){
		bool flag=true;
		for(int j=0;j<c;j++){
			//cout<<v[i][j]<<" "; 
			if(v[i][j]=='#')flag=false;
		}
		if(flag){
			row[i]=false;	
		}
	}
	for(int i=0;i<r;i++){
	//	cout<<row[i]<<" ";
	}
	for(int i=0;i<c;i++){
		bool flag=true;
		for(int j=0;j<r;j++){
			if(v[j][i]=='#')flag=false;
		}
		if(flag){
			col[i]=false;	
		}
	}
	vector<string>v1;
	for(int i=0;i<r;i++){
		string s;
		for(int j=0;j<c;j++){
			if(row[i]==true&&col[j]==true)s.push_back(v[i][j]);
			
		}
		if(!s.empty())
		v1.push_back(s);
		 
	}
	for(int i=0;i<v1.size();i++){
		cout<<v1[i]<<endl;
	}
	// your code goes here
	return 0;
}