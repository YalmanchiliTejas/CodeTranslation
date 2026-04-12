#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main(){
	int n;
	bool f=false;
	while(cin>>n){
		if(!n)break;
		multimap<int,string,greater<int> > teams;
		for(int i=0,w,l,d;i<n;++i){
			string team;
			cin>>team>>w>>l>>d;
			teams.insert(multimap<int,string>::value_type(w*3+d,team));
		}
		if(f)cout<<endl;
		f=true;
		for(multimap<int,string>::iterator it=teams.begin();it!=teams.end();++it) cout<<(*it).second<<","<<(*it).first<<"\n";
	}
	return 0;
}