#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){

	int s1,s2;
	while(cin>>s1>>s2&&!(s1==0&&s2==0)){
		vector<pair<int,char> > v;
		v.push_back(make_pair(s1+s2,'A'));
		for(int i = 0; i < 4; i++){
			cin>>s1>>s2;
			v.push_back(make_pair(s1+s2,'B'+i));
		}
		sort(v.begin(),v.end(),greater<pair<int,char> >());
		cout<<v[0].second<<" "<<v[0].first<<endl;
	}


	return 0;
}