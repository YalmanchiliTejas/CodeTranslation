#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	string S[n];
	for(int i=0;i<n;++i)cin>>S[i];
	map<char,int>Smap;
	vector<char>arr;
	for(int i=0;i<n;++i){
		map<char,int>tmpmap;
		for(int j=0;j<S[i].length();++j){
			if(Smap[S[i][j]]==0 && tmpmap[S[i][j]]==0)arr.push_back(S[i][j]);
			tmpmap[S[i][j]]++;
		}
		if(i==0)Smap=tmpmap;
		else{
			for(int j=0;j<arr.size();++j){
				Smap[arr[j]]=min(Smap[arr[j]],tmpmap[arr[j]]);
			}
		}
	}
	string ans;
	sort(arr.begin(),arr.end());
	for(int i=0;i<arr.size();++i){
		for(int j=0;j<Smap[arr[i]];++j){
			ans+=arr[i];
		}
	}
	cout<<ans<<endl;
}
