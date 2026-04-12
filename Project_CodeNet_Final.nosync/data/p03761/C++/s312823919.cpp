#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int N; cin>>N;
	map<char,int> dict;
	string S; cin>>S;
	for(int i=0;i<S.size();i++){
		dict[S[i]]++;
	}
	for(int i=0;i<N-1;i++){
		cin>>S;
		map<char,int> tmp;
		for(int j=0;j<S.size();j++){
			tmp[S[j]]++;
		}
		for(auto p : dict){
			dict[p.first]=min(p.second,(tmp.count(p.first) ? tmp[p.first] : 0LL));
		}
	}
	string ans="";
	for(auto p : dict){
		for(int j=0;j<p.second;j++){
			ans+=p.first;
		}
	}
	sort(ans.begin(),ans.end());
	cout<<ans<<endl;
}
