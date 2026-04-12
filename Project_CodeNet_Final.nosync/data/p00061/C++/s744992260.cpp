#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
	int a,b;
	vector<int> v;
	map<int,int> mp;
	while(cin>>a,cin.ignore(),cin>>b,a||b){
		mp[a]=b;
		v.push_back(b);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int n;
	while(cin>>n)cout<<v.end()-lower_bound(v.begin(),v.end(),mp[n])<<endl;
	return 0;
}