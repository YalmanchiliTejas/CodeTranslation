#include<bits/stdc++.h>
using namespace std;

using ll=long long; 

void solve(){
	int h,w;
	cin>>h>>w;
	vector<string> s(h);
	for(int i=0; i<h; i++)cin>>s[i];
	for(int i=0; i<h; i++){
		bool flag=false;
		for(int j=0; j<w; j++){
			flag|=(s[i][j]=='#');
		}
		if(!flag){
			for(int j=0; j<w; j++){
				s[i][j]='o';
			}
		}
	}
	for(int i=0; i<w; i++){
		bool flag=false;
		for(int j=0; j<h; j++){
			flag|=(s[j][i]=='#');
		}
		if(!flag){
			for(int j=0; j<h; j++){
				s[j][i]='o';
			}
		}
	}
	for(int i=0; i<h; i++){
		bool flag=false; 
		for(int j=0; j<w; j++){
			if(s[i][j]=='o')continue;
			cout<<s[i][j];
			flag=true;
		}
		if(flag)cout<<endl;
	}
}

signed main(){
	//while(1)
	solve();
}