#include<bits/stdc++.h>
#define inf 0x7FFFFFFF
using namespace std;

int main(){
	cin.tie(0),ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<string>s(n);
	for(auto&i:s)cin>>i;
	vector<vector<int>>v(n,vector<int>(26,0));
	for(int i=0;i<n;++i){
		for(int j=0;j<s.at(i).size();++j){
			++v.at(i).at(s.at(i).at(j)-'a');
		}
	}
	vector<int>ans(26,inf);
	for(int y=0;y<n;++y){
		for(int x=0;x<26;++x){
			ans.at(x)=min(ans.at(x),v.at(y).at(x));
		}
	}
	for(int i=0;i<26;++i){
		while(ans.at(i)){
			cout<<(char)('a'+i);
			--ans.at(i);
		}
	}
	cout<<"\n"s;
}