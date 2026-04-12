#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
bool CMP(const pair<int,string> &x , const pair<int,string> &y){
	return x.first>y.first;
}

int main(void){
	int n ;
	bool o = false;
	while(cin>>n,n){
		vector<pair<int,string> > v;
		while(n--){
			string s; int a,b,c;
			cin>>s>>a>>b>>c;
			v.push_back(make_pair(a*3+c,s));
		}
		
		sort(v.begin(),v.end(),CMP);
		if(o)cout<<endl;
		o = true;
		for(int i = 0 ; i < v.size() ; i ++){
			cout<<v[i].second<<","<<v[i].first<<endl;
		}
	}
}