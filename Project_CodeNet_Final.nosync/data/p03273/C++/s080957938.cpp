#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n,m;
	cin>>n>>m;
	vector<string>v;
	for(int i=0;i<n;i++){
		string s;cin>>s;
		bool t=false;
		for(auto u:s){
			if(u=='#'){
				t=true;
			}
		}
		if(t)v.push_back(s);
	}
	set<int>ind;
	for(int j=0;j<m;j++){
		bool t=false;
		for(int i=0;i<v.size();i++){
			if(v[i][j]=='#'){
				t=true;break;
			}
		}
		if(!t)ind.insert(j);
	}
	for(int i=0;i<v.size();i++){
		for(int j=0;j<m;j++){
			if(ind.find(j)==ind.end()){
				cout<<v[i][j];
			}
		}cout<<endl;
	}
	return 0;
}