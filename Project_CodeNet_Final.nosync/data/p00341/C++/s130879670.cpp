#include <bits/stdc++.h>
using namespace std;

#define rep(a,b) for(int a=0; a<b; ++a)

int main(void){
	map<int,int> mp; bool able=true;
	vector<int> v;
	rep(i,12){
		int e; cin>>e; ++mp[e];
	}
	switch((int)mp.size()){
		case 1 :
			cout<<"yes"<<endl;
			break;
		case 2 :
			for(auto &e:mp) v.emplace_back(e.second);
			if((v[0]==4&&v[1]==8)||(v[0]==8&&v[1]==4)) cout<<"yes"<<endl;
			else cout<<"no"<<endl;
			break;
		case 3 :
			for(auto &e:mp) able&=e.second==4;
			cout<<(able?"yes":"no")<<endl;
			break;
		default :
			cout<<"no"<<endl;
			break;
	}
}
