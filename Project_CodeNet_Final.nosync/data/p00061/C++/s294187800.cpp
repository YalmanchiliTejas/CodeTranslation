#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){

	vector<pair<int,int> > vpii;
	int num,ans;
	char cm;
	while(cin>>num>>cm>>ans&&(num!=0||ans!=0)){
		vpii.push_back(make_pair(ans,num));
	}
	sort(vpii.begin(),vpii.end(),greater<pair<int,int> >());

	int prv=10000000;
	int rank=0;
	map<int,int> mii;
	for(int i = 0; i < vpii.size(); i++){
		if(vpii[i].first<prv){
			rank++;
			mii[vpii[i].second]=rank;
			prv=vpii[i].first;
		}
		else if(vpii[i].first==prv){
			mii[vpii[i].second]=rank;
		}
	}

	int nn;
	while(cin>>nn){
		cout<<mii[nn]<<endl;
	}

	return 0;
}