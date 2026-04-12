#include <bits/stdc++.h>
using namespace std;
int main(){
	char output[6]={'A','B','C','D','E'};
	int a,b;
	while(cin>>a>>b&&a!=0&&b!=0){
		vector<pair<int,int> > data;
		data.push_back(make_pair(a+b,0));
		for(int i=1;i<5;i++){
			cin>>a>>b;
			data.push_back(make_pair(a+b,i));
		}
		sort(data.begin(),data.end());
		cout<<output[data[4].second]<<" "<<data[4].first<<endl;
	}
}