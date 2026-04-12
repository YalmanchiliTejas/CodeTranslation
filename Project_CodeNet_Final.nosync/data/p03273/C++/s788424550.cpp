#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0),ios::sync_with_stdio(false);
	int h,w; cin>>h>>w;
	vector<string>a(h); for(auto&i:a)cin>>i;
	for(int i=0;i<h;++i){
		bool any=false;
		for(int j=0;j<w;++j){
			if(a.at(i).at(j)=='#')any=true;
		}
		if(!any)for(int j=0;j<w;++j){
			a.at(i).at(j)='@';
		}
	}
	for(int i=0;i<w;++i){
		bool any=false;
		for(int j=0;j<h;++j){
			if(a.at(j).at(i)=='#')any=true;
		}
		if(!any)for(int j=0;j<h;++j){
			a.at(j).at(i)='@';
		}
	}
	for(int i=0;i<h;++i){
		int cnt=0;
		for(int j=0;j<w;++j){
			if(a.at(i).at(j)=='@')++cnt;
			else cout<<a.at(i).at(j);
		}
		if(cnt!=w)cout<<"\n"s;
	}
}