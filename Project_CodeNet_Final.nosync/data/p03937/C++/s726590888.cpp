#include<bits/stdc++.h>
using namespace std;

using ll=long long; 

void solve(){
	int h,w;
	cin>>h>>w;
	vector<string> fld(h);
	vector<vector<bool>> used(h,vector<bool>(w));
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			used[i][j]=0;
		}
	}
	for(int i=0; i<h; i++)cin>>fld[i];
	int cur=0;
	for(int i=0; i<h; i++){
		while(1){
			if(cur==w){
				cur--;
				break;
			}
			if(fld[i][cur]=='#'){
				used[i][cur]=1;
				cur++;
			}
			else{
				cur--;
				break;
			}
		}
	}
	/*
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cout<<used[i][j];
		}
		cout<<endl;
	}
	*/
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(!((fld[i][j]=='#'&&used[i][j])||(fld[i][j]=='.'&&!used[i][j]))){
				cout<<"Impossible"<<endl;
				return;
			}
		}
	}
	cout<<"Possible"<<endl;
}

signed main(){
	//while(1)
	solve();
}