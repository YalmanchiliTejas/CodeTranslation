#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	map<char,int> x;
	for(char c='a';c<='z';++c)
		x[c];
	string s;
	vector<string> y;
	while(t--){
		cin>>s;
		y.push_back(s);
	}
	for(auto i:x){
		bool find=true;
		int ma=100;
		for(auto j:y){
			int cnt=0;
			for(auto k:j){
				if(k==i.first)
					++cnt;
			}
			if(cnt==0)
				find=false;
			else
				ma=min(ma,cnt);
		}
		if(find)
			x[i.first]=ma;
	}
	string ans;
	for(auto i:x){
		if(i.second)
			ans+=string(i.second,i.first);
	}
	cout<<ans;

}