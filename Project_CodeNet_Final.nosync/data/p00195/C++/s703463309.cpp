#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int main(){
	int a,b;
	char mise[4]={'B','C','D','E'};
	while(cin>>a>>b){
		vector<pair<int,char> > data;
		if(a==0&&b==0)break;
		data.push_back(make_pair(a+b,'A'));
		for(int i=0;i<4;i++){
			cin>>a>>b;
			data.push_back(make_pair(a+b,mise[i]));
		}
		sort(data.begin(),data.end());
		cout<<data[4].second<<" "<<data[4].first<<endl;
	}
			
}