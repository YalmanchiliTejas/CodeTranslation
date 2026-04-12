#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){

	int n;
	bool f=false;
	while(cin>>n&&n!=0){
		if(f)
			cout<<endl;
		f=true;
		vector<pair<int,pair<int,string> > > v;
		string team;
		int w,l,d;
		for(int i = 0; i < n; i++){
			cin>>team>>w>>l>>d;
			v.push_back(make_pair(w*3+d*1,make_pair(-i,team)));
		}
		sort(v.begin(),v.end(),greater<pair<int,pair<int,string> > >());
		for(int i = 0; i < v.size(); i++){
			cout<<v[i].second.second<<","<<v[i].first<<endl;
		}
	}

	return 0;
}